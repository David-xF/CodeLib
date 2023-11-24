#pragma once

#include <code/tcpgecko.h>

#define CURLOPTTYPE_LONG          00000
#define CURLOPTTYPE_OBJECTPOINT   10000
#define CURLOPTTYPE_FUNCTIONPOINT 20000
#define CURLOPTTYPE_OFF_T         30000

#define CINIT(name, type, number) CURLOPT_##name = CURLOPTTYPE_##type + number

#define CURL_ERROR_SIZE 256

enum CURLOption : int {
    CINIT(FILE,          OBJECTPOINT,    1),
    CINIT(URL,           OBJECTPOINT,    2),
    CINIT(PORT,          LONG,           3),
    CINIT(INFILE,        OBJECTPOINT,    9),
    CINIT(ERRORBUFFER,   OBJECTPOINT,   10),
    CINIT(WRITEFUNCTION, FUNCTIONPOINT, 11),
    CINIT(READFUNCTION,  FUNCTIONPOINT, 12),
    CINIT(IDK,           OBJECTPOINT,   12),
    CINIT(POSTFIELDS,    OBJECTPOINT,   15),
    CINIT(USERAGENT,     OBJECTPOINT,   18),
    CINIT(HTTPHEADER,    OBJECTPOINT,   23),  
    CINIT(CUSTOMREQUEST, OBJECTPOINT,   36),
    CINIT(POST,          LONG,          47),
    CINIT(POSTFIELDSIZE, LONG,          60),
};

struct curl_slist {

};

EXPORT_DECL(void*, curl_easy_init, void);
EXPORT_DECL(void, curl_easy_cleanup, void*);
EXPORT_DECL(int, curl_easy_perform, void*);
EXPORT_DECL(void, curl_easy_setopt, void*, CURLOption, const void*);
EXPORT_DECL(curl_slist*, curl_slist_append, curl_slist* list, const char* string);

void InitLibCurlFunctionPointers(void) {
    unsigned int* funcPointer = 0;
    uint32_t libcurl_handle;
    OSDynLoad_Acquire("nlibcurl.rpl", &libcurl_handle);
    OS_FIND_EXPORT(libcurl_handle, curl_easy_init);
    OS_FIND_EXPORT(libcurl_handle, curl_easy_cleanup);
    OS_FIND_EXPORT(libcurl_handle, curl_easy_perform);
    OS_FIND_EXPORT(libcurl_handle, curl_easy_setopt);
    OS_FIND_EXPORT(libcurl_handle, curl_slist_append);
}