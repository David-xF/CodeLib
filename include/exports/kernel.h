#pragma once

#include <code/tcpgecko.h>

EXPORT_DECL(void, DCFlushRange, const void* addr, uint32_t length);
EXPORT_DECL(void*, OSEffectiveToPhysical, const void*);
EXPORT_DECL(void, OSFatal, const char *msg);

void SC0x25_KernelCopyData(unsigned int addr, unsigned int src, unsigned int len) {
    asm volatile("li 0, 0x2500");
    asm volatile("sc");
    asm volatile("blr");
}

void InitKernelFunctionPointers() {
    uint32_t coreinit_handle;
    uint32_t* funcPointer = 0;
    OSDynLoad_Acquire("coreinit.rpl", &coreinit_handle);
    OS_FIND_EXPORT(coreinit_handle, DCFlushRange);
    OS_FIND_EXPORT(coreinit_handle, OSEffectiveToPhysical);
    OS_FIND_EXPORT(coreinit_handle, OSFatal);
}

// TODO Variable size, not hard-coded
#define DATA_BUFFER_SIZE 0x20
unsigned char* kernelCopyBufferOld[DATA_BUFFER_SIZE];

void kernelCopyData(unsigned char* destinationBuffer, unsigned char* sourceBuffer, unsigned int length) {
	if (length > DATA_BUFFER_SIZE) {
		OSFatal("Kernel copy buffer size exceeded");
	}
	
	memcpy(kernelCopyBufferOld, sourceBuffer, length);
	SC0x25_KernelCopyData((unsigned int) OSEffectiveToPhysical(destinationBuffer), (unsigned int) &kernelCopyBufferOld,
						  length);
	DCFlushRange(destinationBuffer, (uint32_t) length);
}

unsigned char* kernelCopyBuffer[sizeof(int)];

void kernelCopyInt(unsigned char* destinationBuffer, unsigned char* sourceBuffer, unsigned int length) {
	memcpy(kernelCopyBuffer, sourceBuffer, length);
	unsigned int destinationAddress = (unsigned int) OSEffectiveToPhysical(destinationBuffer);
	SC0x25_KernelCopyData(destinationAddress, (unsigned int) &kernelCopyBuffer, length);
	DCFlushRange(destinationBuffer, (uint32_t) length);
}

void writeKernelMemory(const void* address, uint32_t value) {
	((int*) kernelCopyBuffer)[0] = value;
	kernelCopyInt((unsigned char*) address, (unsigned char*) kernelCopyBuffer, sizeof(int));
}