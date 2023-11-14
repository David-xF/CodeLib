#pragma once

#include <code/tcpgecko.h>

uint32_t hostIpAddress = 0;

#define INADDR_ANY      0

#define AF_INET         2

#define SOCK_STREAM     1
#define SOCK_DGRAM      2

#define IPPROTO_IP      0
#define IPPROTO_TCP     6
#define IPPROTO_UDP     17

#define TCP_NODELAY     0x2004

#define SOL_SOCKET      -1
#define SO_REUSEADDR    0x0004
#define SO_NONBLOCK     0x1016
#define SO_MYADDR       0x1013

#define htonl(x) x
#define htons(x) x
#define ntohl(x) x
#define ntohs(x) x

struct in_addr {
	uint32_t s_addr;
};

struct sockaddr_in {
	short sin_family;
	unsigned short sin_port;
	in_addr sin_addr;
	char sin_zero[8];
};

struct sockaddr {
	unsigned short sa_family;
	char sa_data[14];
};

EXPORT_DECL(int,   socket_lib_init, void);
EXPORT_DECL(int,   socket_lib_finish, void);
EXPORT_DECL(int,   socket, int domain, int type, int protocol);
EXPORT_DECL(int,   socketclose, int s);
EXPORT_DECL(int,   connect, int s, void* addr, int addrlen);
EXPORT_DECL(int,   bind, int s, sockaddr* name, int namelen);
EXPORT_DECL(int,   listen, int s,uint32_t backlog);
EXPORT_DECL(int,   accept, int s, sockaddr* addr, int* addrlen);
EXPORT_DECL(int,   send, int s, const void* buffer, int size, int flags);
EXPORT_DECL(int,   recv, int s, void* buffer, int size, int flags);
EXPORT_DECL(int,   sendto, int s, const void* buffer, int size, int flags, const sockaddr* dest, int dest_len);
EXPORT_DECL(int,   setsockopt, int s, int level, int optname, void* optval, int optlen);
EXPORT_DECL(char*, inet_ntoa, in_addr in);
EXPORT_DECL(int,   inet_aton, const char* cp, in_addr* inp);

void InitSocketFunctionPointers(void) {
    uint32_t nsysnet_handle;
    uint32_t* funcPointer = 0;
    OSDynLoad_Acquire("nsysnet.rpl", &nsysnet_handle);

    uint32_t nn_ac_handle;
    int(*ACInitialize)();
    int(*ACGetStartupId) (uint32_t* id);
    int(*ACConnectWithConfigId) (uint32_t id);
    int(*ACGetAssignedAddress) (uint32_t* ip);
    OSDynLoad_Acquire("nn_ac.rpl", &nn_ac_handle);
    OSDynLoad_FindExport(nn_ac_handle, 0, "ACInitialize", &ACInitialize);
    OSDynLoad_FindExport(nn_ac_handle, 0, "ACGetStartupId", &ACGetStartupId);
    OSDynLoad_FindExport(nn_ac_handle, 0, "ACConnectWithConfigId",&ACConnectWithConfigId);
    OSDynLoad_FindExport(nn_ac_handle, 0, "ACGetAssignedAddress",&ACGetAssignedAddress);

    OS_FIND_EXPORT(nsysnet_handle, socket_lib_init);
    OS_FIND_EXPORT(nsysnet_handle, socket_lib_finish);
    OS_FIND_EXPORT(nsysnet_handle, socket);
    OS_FIND_EXPORT(nsysnet_handle, socketclose);
    OS_FIND_EXPORT(nsysnet_handle, connect);
    OS_FIND_EXPORT(nsysnet_handle, bind);
    OS_FIND_EXPORT(nsysnet_handle, listen);
    OS_FIND_EXPORT(nsysnet_handle, accept);
    OS_FIND_EXPORT(nsysnet_handle, send);
    OS_FIND_EXPORT(nsysnet_handle, recv);
    OS_FIND_EXPORT(nsysnet_handle, sendto);
    OS_FIND_EXPORT(nsysnet_handle, setsockopt);
    OS_FIND_EXPORT(nsysnet_handle, inet_ntoa);
    OS_FIND_EXPORT(nsysnet_handle, inet_aton);

    uint32_t nn_startupid;
    ACInitialize();
    ACGetStartupId(&nn_startupid);
    ACConnectWithConfigId(nn_startupid);
    ACGetAssignedAddress(&hostIpAddress);

    socket_lib_init();
}