/*!
 * \file
 *
 * \brief Source file for UpnpLib methods.
 *
 * Do not edit this file, it is automatically generated. Please look at
 * generator.c.
 *
 * \author Marcelo Roberto Jimenez
 */
#include "config.h"

#include "UpnpLib.h"

#include <stdlib.h> /* for calloc(), free() */
#include <string.h> /* for strlen(), strdup() */

struct s_UpnpLib
{
        struct VirtualDirCallbacks m_virtualDirCallback;
        virtualDirList *m_pVirtualDirList;
        ithread_mutex_t m_GlobalClientSubscribeMutex;
        ithread_rwlock_t m_GlobalHndRWLock;
        ithread_mutex_t m_gUUIDMutex;
        ithread_mutex_t m_gSDKInitMutex;
        TimerThread m_gTimerThread;
        ThreadPool m_gSendThreadPool;
        ThreadPool m_gRecvThreadPool;
        ThreadPool m_gMiniServerThreadPool;
        WebServerState m_bWebServerState;
        UpnpString *m_gIF_NAME;
        UpnpString *m_gIF_IPV4;
        UpnpString *m_gIF_IPV4_NETMASK;
        UpnpString *m_gIF_IPV6;
        unsigned m_gIF_IPV6_PREFIX_LENGTH;
        UpnpString *m_gIF_IPV6_ULA_GUA;
        unsigned m_gIF_IPV6_ULA_GUA_PREFIX_LENGTH;
        unsigned m_gIF_INDEX;
        unsigned short m_LOCAL_PORT_V4;
        unsigned short m_LOCAL_PORT_V6;
        unsigned short m_LOCAL_PORT_V6_ULA_GUA;
        handle_table_t m_HandleTable;
        doc_type_array_t m_gMediaTypeArray;
        xml_alias_t m_gAliasDoc;
        ithread_mutex_t m_gWebMutex;
        membuffer m_gDocumentRootDir;
        size_t m_g_maxContentLength;
        int m_g_UpnpSdkEQMaxLen;
        int m_g_UpnpSdkEQMaxAge;
        int m_UpnpSdkInit;
        int m_UpnpSdkClientRegistered;
        int m_UpnpSdkDeviceRegisteredV4;
        int m_UpnpSdkDeviceRegisteredV6;
        UpnpString *m_gUpnpSdkNLSuuid;
#ifdef UPNP_ENABLE_OPEN_SSL
        SSL_CTX *m_gSslCtx;
#endif
        ithread_mutex_t m_LogMutex;
        Upnp_LogLevel m_LogLevel;
        FILE *m_LogFp;
        int m_gLogIsStderr;
        int m_SetLogWasCalled;
        int m_LogInitWasCalled;
        char *m_LogFileName;
};

UpnpLib *UpnpLib_new()
{
        struct s_UpnpLib *p = calloc(1, sizeof(struct s_UpnpLib));

        if (!p) {
                return 0;
        }

        /* memset(&p->m_virtualDirCallback, 0, sizeof (struct
         * VirtualDirCallbacks)); */
        /*p->m_pVirtualDirList = 0;*/
        pthread_mutex_init(&p->m_GlobalClientSubscribeMutex, 0);
        ;
        /* memset(&p->m_GlobalHndRWLock, 0, sizeof (ithread_rwlock_t)); */
        pthread_mutex_init(&p->m_gUUIDMutex, 0);
        ;
        pthread_mutex_init(&p->m_gSDKInitMutex, 0);
        ;
        /* memset(&p->m_gTimerThread, 0, sizeof (TimerThread)); */
        /* memset(&p->m_gSendThreadPool, 0, sizeof (ThreadPool)); */
        /* memset(&p->m_gRecvThreadPool, 0, sizeof (ThreadPool)); */
        /* memset(&p->m_gMiniServerThreadPool, 0, sizeof (ThreadPool)); */
        /*p->m_bWebServerState = 0;*/
        p->m_gIF_NAME = UpnpString_new();
        p->m_gIF_IPV4 = UpnpString_new();
        p->m_gIF_IPV4_NETMASK = UpnpString_new();
        p->m_gIF_IPV6 = UpnpString_new();
        /*p->m_gIF_IPV6_PREFIX_LENGTH = 0;*/
        p->m_gIF_IPV6_ULA_GUA = UpnpString_new();
        /*p->m_gIF_IPV6_ULA_GUA_PREFIX_LENGTH = 0;*/
        p->m_gIF_INDEX = (unsigned)-1;
        /*p->m_LOCAL_PORT_V4 = 0;*/
        /*p->m_LOCAL_PORT_V6 = 0;*/
        /*p->m_LOCAL_PORT_V6_ULA_GUA = 0;*/
        /* memset(&p->m_HandleTable, 0, sizeof (handle_table_t)); */
        /* memset(&p->m_gMediaTypeArray, 0, sizeof (doc_type_array_t)); */
        /* memset(&p->m_gAliasDoc, 0, sizeof (xml_alias_t)); */
        pthread_mutex_init(&p->m_gWebMutex, 0);
        ;
        /* memset(&p->m_gDocumentRootDir, 0, sizeof (membuffer)); */
        /*p->m_g_maxContentLength = 0;*/
        /*p->m_g_UpnpSdkEQMaxLen = 0;*/
        /*p->m_g_UpnpSdkEQMaxAge = 0;*/
        /*p->m_UpnpSdkInit = 0;*/
        /*p->m_UpnpSdkClientRegistered = 0;*/
        /*p->m_UpnpSdkDeviceRegisteredV4 = 0;*/
        /*p->m_UpnpSdkDeviceRegisteredV6 = 0;*/
        p->m_gUpnpSdkNLSuuid = UpnpString_new();
#ifdef UPNP_ENABLE_OPEN_SSL
        /*p->m_gSslCtx = 0;*/
#endif
        pthread_mutex_init(&p->m_gSDKInitMutex, 0);
        ;
        p->m_LogLevel = UPNP_DEFAULT_LOG_LEVEL;
        /*p->m_LogFp = 0;*/
        /*p->m_gLogIsStderr = 0;*/
        /*p->m_SetLogWasCalled = 0;*/
        /*p->m_LogInitWasCalled = 0;*/
        /*p->m_LogFileName = 0;*/

        return (UpnpLib *)p;
}

void UpnpLib_delete(UpnpLib *q)
{
        struct s_UpnpLib *p = (struct s_UpnpLib *)q;

        if (!p) {
                return;
        }

        p->m_LogFileName = 0;
        p->m_LogInitWasCalled = 0;
        p->m_SetLogWasCalled = 0;
        p->m_gLogIsStderr = 0;
        p->m_LogFp = 0;
        p->m_LogLevel = UPNP_DEFAULT_LOG_LEVEL;
        memset(&p->m_LogMutex, 0, sizeof(ithread_mutex_t));
#ifdef UPNP_ENABLE_OPEN_SSL
        p->m_gSslCtx = 0;
#endif
        UpnpString_delete(p->m_gUpnpSdkNLSuuid);
        p->m_gUpnpSdkNLSuuid = 0;
        p->m_UpnpSdkDeviceRegisteredV6 = 0;
        p->m_UpnpSdkDeviceRegisteredV4 = 0;
        p->m_UpnpSdkClientRegistered = 0;
        p->m_UpnpSdkInit = 0;
        p->m_g_UpnpSdkEQMaxAge = 0;
        p->m_g_UpnpSdkEQMaxLen = 0;
        p->m_g_maxContentLength = 0;
        memset(&p->m_gDocumentRootDir, 0, sizeof(membuffer));
        memset(&p->m_gWebMutex, 0, sizeof(ithread_mutex_t));
        memset(&p->m_gAliasDoc, 0, sizeof(xml_alias_t));
        memset(&p->m_gMediaTypeArray, 0, sizeof(doc_type_array_t));
        memset(&p->m_HandleTable, 0, sizeof(handle_table_t));
        p->m_LOCAL_PORT_V6_ULA_GUA = 0;
        p->m_LOCAL_PORT_V6 = 0;
        p->m_LOCAL_PORT_V4 = 0;
        p->m_gIF_INDEX = (unsigned)-1;
        p->m_gIF_IPV6_ULA_GUA_PREFIX_LENGTH = 0;
        UpnpString_delete(p->m_gIF_IPV6_ULA_GUA);
        p->m_gIF_IPV6_ULA_GUA = 0;
        p->m_gIF_IPV6_PREFIX_LENGTH = 0;
        UpnpString_delete(p->m_gIF_IPV6);
        p->m_gIF_IPV6 = 0;
        UpnpString_delete(p->m_gIF_IPV4_NETMASK);
        p->m_gIF_IPV4_NETMASK = 0;
        UpnpString_delete(p->m_gIF_IPV4);
        p->m_gIF_IPV4 = 0;
        UpnpString_delete(p->m_gIF_NAME);
        p->m_gIF_NAME = 0;
        p->m_bWebServerState = 0;
        memset(&p->m_gMiniServerThreadPool, 0, sizeof(ThreadPool));
        memset(&p->m_gRecvThreadPool, 0, sizeof(ThreadPool));
        memset(&p->m_gSendThreadPool, 0, sizeof(ThreadPool));
        memset(&p->m_gTimerThread, 0, sizeof(TimerThread));
        memset(&p->m_gSDKInitMutex, 0, sizeof(ithread_mutex_t));
        memset(&p->m_gUUIDMutex, 0, sizeof(ithread_mutex_t));
        memset(&p->m_GlobalHndRWLock, 0, sizeof(ithread_rwlock_t));
        memset(&p->m_GlobalClientSubscribeMutex, 0, sizeof(ithread_mutex_t));
        p->m_pVirtualDirList = 0;
        memset(&p->m_virtualDirCallback, 0, sizeof(struct VirtualDirCallbacks));

        free(p);
}

int UpnpLib_assign(UpnpLib *p, const UpnpLib *q)
{
        int ok = 1;

        if (p != q) {
                ok = ok &&
                        UpnpLib_set_virtualDirCallback(
                                p, UpnpLib_get_virtualDirCallback(q));
                ok = ok &&
                        UpnpLib_set_pVirtualDirList(
                                p, UpnpLib_get_pVirtualDirList(q));
                ok = ok &&
                        UpnpLib_set_GlobalClientSubscribeMutex(
                                p, UpnpLib_get_GlobalClientSubscribeMutex(q));
                ok = ok &&
                        UpnpLib_set_GlobalHndRWLock(
                                p, UpnpLib_get_GlobalHndRWLock(q));
                ok = ok && UpnpLib_set_gUUIDMutex(p, UpnpLib_get_gUUIDMutex(q));
                ok = ok &&
                        UpnpLib_set_gSDKInitMutex(
                                p, UpnpLib_get_gSDKInitMutex(q));
                ok = ok &&
                        UpnpLib_set_gTimerThread(
                                p, UpnpLib_get_gTimerThread(q));
                ok = ok &&
                        UpnpLib_set_gSendThreadPool(
                                p, UpnpLib_get_gSendThreadPool(q));
                ok = ok &&
                        UpnpLib_set_gRecvThreadPool(
                                p, UpnpLib_get_gRecvThreadPool(q));
                ok = ok &&
                        UpnpLib_set_gMiniServerThreadPool(
                                p, UpnpLib_get_gMiniServerThreadPool(q));
                ok = ok &&
                        UpnpLib_set_bWebServerState(
                                p, UpnpLib_get_bWebServerState(q));
                ok = ok && UpnpLib_set_gIF_NAME(p, UpnpLib_get_gIF_NAME(q));
                ok = ok && UpnpLib_set_gIF_IPV4(p, UpnpLib_get_gIF_IPV4(q));
                ok = ok &&
                        UpnpLib_set_gIF_IPV4_NETMASK(
                                p, UpnpLib_get_gIF_IPV4_NETMASK(q));
                ok = ok && UpnpLib_set_gIF_IPV6(p, UpnpLib_get_gIF_IPV6(q));
                ok = ok &&
                        UpnpLib_set_gIF_IPV6_PREFIX_LENGTH(
                                p, UpnpLib_get_gIF_IPV6_PREFIX_LENGTH(q));
                ok = ok &&
                        UpnpLib_set_gIF_IPV6_ULA_GUA(
                                p, UpnpLib_get_gIF_IPV6_ULA_GUA(q));
                ok = ok &&
                        UpnpLib_set_gIF_IPV6_ULA_GUA_PREFIX_LENGTH(p,
                                UpnpLib_get_gIF_IPV6_ULA_GUA_PREFIX_LENGTH(q));
                ok = ok && UpnpLib_set_gIF_INDEX(p, UpnpLib_get_gIF_INDEX(q));
                ok = ok &&
                        UpnpLib_set_LOCAL_PORT_V4(
                                p, UpnpLib_get_LOCAL_PORT_V4(q));
                ok = ok &&
                        UpnpLib_set_LOCAL_PORT_V6(
                                p, UpnpLib_get_LOCAL_PORT_V6(q));
                ok = ok &&
                        UpnpLib_set_LOCAL_PORT_V6_ULA_GUA(
                                p, UpnpLib_get_LOCAL_PORT_V6_ULA_GUA(q));
                ok = ok &&
                        UpnpLib_set_HandleTable(p, UpnpLib_get_HandleTable(q));
                ok = ok &&
                        UpnpLib_set_gMediaTypeArray(
                                p, UpnpLib_get_gMediaTypeArray(q));
                ok = ok && UpnpLib_set_gAliasDoc(p, UpnpLib_get_gAliasDoc(q));
                ok = ok && UpnpLib_set_gWebMutex(p, UpnpLib_get_gWebMutex(q));
                ok = ok &&
                        UpnpLib_set_gDocumentRootDir(
                                p, UpnpLib_get_gDocumentRootDir(q));
                ok = ok &&
                        UpnpLib_set_g_maxContentLength(
                                p, UpnpLib_get_g_maxContentLength(q));
                ok = ok &&
                        UpnpLib_set_g_UpnpSdkEQMaxLen(
                                p, UpnpLib_get_g_UpnpSdkEQMaxLen(q));
                ok = ok &&
                        UpnpLib_set_g_UpnpSdkEQMaxAge(
                                p, UpnpLib_get_g_UpnpSdkEQMaxAge(q));
                ok = ok &&
                        UpnpLib_set_UpnpSdkInit(p, UpnpLib_get_UpnpSdkInit(q));
                ok = ok &&
                        UpnpLib_set_UpnpSdkClientRegistered(
                                p, UpnpLib_get_UpnpSdkClientRegistered(q));
                ok = ok &&
                        UpnpLib_set_UpnpSdkDeviceRegisteredV4(
                                p, UpnpLib_get_UpnpSdkDeviceRegisteredV4(q));
                ok = ok &&
                        UpnpLib_set_UpnpSdkDeviceRegisteredV6(
                                p, UpnpLib_get_UpnpSdkDeviceRegisteredV6(q));
                ok = ok &&
                        UpnpLib_set_gUpnpSdkNLSuuid(
                                p, UpnpLib_get_gUpnpSdkNLSuuid(q));
#ifdef UPNP_ENABLE_OPEN_SSL
                ok = ok && UpnpLib_set_gSslCtx(p, UpnpLib_get_gSslCtx(q));
#endif
                ok = ok && UpnpLib_set_LogMutex(p, UpnpLib_get_LogMutex(q));
                ok = ok && UpnpLib_set_LogLevel(p, UpnpLib_get_LogLevel(q));
                ok = ok && UpnpLib_set_LogFp(p, UpnpLib_get_LogFp(q));
                ok = ok &&
                        UpnpLib_set_LogIsStderr(p, UpnpLib_get_LogIsStderr(q));
                ok = ok &&
                        UpnpLib_set_SetLogWasCalled(
                                p, UpnpLib_get_SetLogWasCalled(q));
                ok = ok &&
                        UpnpLib_set_LogInitWasCalled(
                                p, UpnpLib_get_LogInitWasCalled(q));
                ok = ok &&
                        UpnpLib_set_LogFileName(p, UpnpLib_get_LogFileName(q));
        }

        return ok;
}

UpnpLib *UpnpLib_dup(const UpnpLib *q)
{
        UpnpLib *p = UpnpLib_new();

        if (!p) {
                return 0;
        }

        UpnpLib_assign(p, q);

        return p;
}

const struct VirtualDirCallbacks *UpnpLib_get_virtualDirCallback(
        const UpnpLib *p)
{
        return &p->m_virtualDirCallback;
}

struct VirtualDirCallbacks *UpnpLib_getnc_virtualDirCallback(UpnpLib *p)
{
        return &p->m_virtualDirCallback;
}

int UpnpLib_set_virtualDirCallback(
        UpnpLib *p, const struct VirtualDirCallbacks *buf)
{
        p->m_virtualDirCallback = *buf;

        return 1;
}

void UpnpLib_clear_virtualDirCallback(UpnpLib *p)
{
        memset(&p->m_virtualDirCallback, 0, sizeof(struct VirtualDirCallbacks));
}

virtualDirList *UpnpLib_get_pVirtualDirList(const UpnpLib *p)
{
        return p->m_pVirtualDirList;
}

int UpnpLib_set_pVirtualDirList(UpnpLib *p, virtualDirList *n)
{
        p->m_pVirtualDirList = n;

        return 1;
}

const ithread_mutex_t *UpnpLib_get_GlobalClientSubscribeMutex(const UpnpLib *p)
{
        return &p->m_GlobalClientSubscribeMutex;
}

ithread_mutex_t *UpnpLib_getnc_GlobalClientSubscribeMutex(UpnpLib *p)
{
        return &p->m_GlobalClientSubscribeMutex;
}

int UpnpLib_set_GlobalClientSubscribeMutex(
        UpnpLib *p, const ithread_mutex_t *buf)
{
        p->m_GlobalClientSubscribeMutex = *buf;

        return 1;
}

void UpnpLib_clear_GlobalClientSubscribeMutex(UpnpLib *p)
{
        memset(&p->m_GlobalClientSubscribeMutex, 0, sizeof(ithread_mutex_t));
}

const ithread_rwlock_t *UpnpLib_get_GlobalHndRWLock(const UpnpLib *p)
{
        return &p->m_GlobalHndRWLock;
}

ithread_rwlock_t *UpnpLib_getnc_GlobalHndRWLock(UpnpLib *p)
{
        return &p->m_GlobalHndRWLock;
}

int UpnpLib_set_GlobalHndRWLock(UpnpLib *p, const ithread_rwlock_t *buf)
{
        p->m_GlobalHndRWLock = *buf;

        return 1;
}

void UpnpLib_clear_GlobalHndRWLock(UpnpLib *p)
{
        memset(&p->m_GlobalHndRWLock, 0, sizeof(ithread_rwlock_t));
}

const ithread_mutex_t *UpnpLib_get_gUUIDMutex(const UpnpLib *p)
{
        return &p->m_gUUIDMutex;
}

ithread_mutex_t *UpnpLib_getnc_gUUIDMutex(UpnpLib *p)
{
        return &p->m_gUUIDMutex;
}

int UpnpLib_set_gUUIDMutex(UpnpLib *p, const ithread_mutex_t *buf)
{
        p->m_gUUIDMutex = *buf;

        return 1;
}

void UpnpLib_clear_gUUIDMutex(UpnpLib *p)
{
        memset(&p->m_gUUIDMutex, 0, sizeof(ithread_mutex_t));
}

const ithread_mutex_t *UpnpLib_get_gSDKInitMutex(const UpnpLib *p)
{
        return &p->m_gSDKInitMutex;
}

ithread_mutex_t *UpnpLib_getnc_gSDKInitMutex(UpnpLib *p)
{
        return &p->m_gSDKInitMutex;
}

int UpnpLib_set_gSDKInitMutex(UpnpLib *p, const ithread_mutex_t *buf)
{
        p->m_gSDKInitMutex = *buf;

        return 1;
}

void UpnpLib_clear_gSDKInitMutex(UpnpLib *p)
{
        memset(&p->m_gSDKInitMutex, 0, sizeof(ithread_mutex_t));
}

const TimerThread *UpnpLib_get_gTimerThread(const UpnpLib *p)
{
        return &p->m_gTimerThread;
}

TimerThread *UpnpLib_getnc_gTimerThread(UpnpLib *p)
{
        return &p->m_gTimerThread;
}

int UpnpLib_set_gTimerThread(UpnpLib *p, const TimerThread *buf)
{
        p->m_gTimerThread = *buf;

        return 1;
}

void UpnpLib_clear_gTimerThread(UpnpLib *p)
{
        memset(&p->m_gTimerThread, 0, sizeof(TimerThread));
}

const ThreadPool *UpnpLib_get_gSendThreadPool(const UpnpLib *p)
{
        return &p->m_gSendThreadPool;
}

ThreadPool *UpnpLib_getnc_gSendThreadPool(UpnpLib *p)
{
        return &p->m_gSendThreadPool;
}

int UpnpLib_set_gSendThreadPool(UpnpLib *p, const ThreadPool *buf)
{
        p->m_gSendThreadPool = *buf;

        return 1;
}

void UpnpLib_clear_gSendThreadPool(UpnpLib *p)
{
        memset(&p->m_gSendThreadPool, 0, sizeof(ThreadPool));
}

const ThreadPool *UpnpLib_get_gRecvThreadPool(const UpnpLib *p)
{
        return &p->m_gRecvThreadPool;
}

ThreadPool *UpnpLib_getnc_gRecvThreadPool(UpnpLib *p)
{
        return &p->m_gRecvThreadPool;
}

int UpnpLib_set_gRecvThreadPool(UpnpLib *p, const ThreadPool *buf)
{
        p->m_gRecvThreadPool = *buf;

        return 1;
}

void UpnpLib_clear_gRecvThreadPool(UpnpLib *p)
{
        memset(&p->m_gRecvThreadPool, 0, sizeof(ThreadPool));
}

const ThreadPool *UpnpLib_get_gMiniServerThreadPool(const UpnpLib *p)
{
        return &p->m_gMiniServerThreadPool;
}

ThreadPool *UpnpLib_getnc_gMiniServerThreadPool(UpnpLib *p)
{
        return &p->m_gMiniServerThreadPool;
}

int UpnpLib_set_gMiniServerThreadPool(UpnpLib *p, const ThreadPool *buf)
{
        p->m_gMiniServerThreadPool = *buf;

        return 1;
}

void UpnpLib_clear_gMiniServerThreadPool(UpnpLib *p)
{
        memset(&p->m_gMiniServerThreadPool, 0, sizeof(ThreadPool));
}

WebServerState UpnpLib_get_bWebServerState(const UpnpLib *p)
{
        return p->m_bWebServerState;
}

int UpnpLib_set_bWebServerState(UpnpLib *p, WebServerState n)
{
        p->m_bWebServerState = n;

        return 1;
}

const UpnpString *UpnpLib_get_gIF_NAME(const UpnpLib *p)
{
        return p->m_gIF_NAME;
}

int UpnpLib_set_gIF_NAME(UpnpLib *p, const UpnpString *s)
{
        const char *q = UpnpString_get_String(s);

        return UpnpString_set_String(p->m_gIF_NAME, q);
}

size_t UpnpLib_get_gIF_NAME_Length(const UpnpLib *p)
{
        return UpnpString_get_Length(UpnpLib_get_gIF_NAME(p));
}

const char *UpnpLib_get_gIF_NAME_cstr(const UpnpLib *p)
{
        return UpnpString_get_String(UpnpLib_get_gIF_NAME(p));
}

int UpnpLib_strcpy_gIF_NAME(UpnpLib *p, const char *s)
{
        return UpnpString_set_String(p->m_gIF_NAME, s);
}

int UpnpLib_strncpy_gIF_NAME(UpnpLib *p, const char *s, size_t n)
{
        return UpnpString_set_StringN(p->m_gIF_NAME, s, n);
}

void UpnpLib_clear_gIF_NAME(UpnpLib *p) { UpnpString_clear(p->m_gIF_NAME); }

const UpnpString *UpnpLib_get_gIF_IPV4(const UpnpLib *p)
{
        return p->m_gIF_IPV4;
}

int UpnpLib_set_gIF_IPV4(UpnpLib *p, const UpnpString *s)
{
        const char *q = UpnpString_get_String(s);

        return UpnpString_set_String(p->m_gIF_IPV4, q);
}

size_t UpnpLib_get_gIF_IPV4_Length(const UpnpLib *p)
{
        return UpnpString_get_Length(UpnpLib_get_gIF_IPV4(p));
}

const char *UpnpLib_get_gIF_IPV4_cstr(const UpnpLib *p)
{
        return UpnpString_get_String(UpnpLib_get_gIF_IPV4(p));
}

int UpnpLib_strcpy_gIF_IPV4(UpnpLib *p, const char *s)
{
        return UpnpString_set_String(p->m_gIF_IPV4, s);
}

int UpnpLib_strncpy_gIF_IPV4(UpnpLib *p, const char *s, size_t n)
{
        return UpnpString_set_StringN(p->m_gIF_IPV4, s, n);
}

void UpnpLib_clear_gIF_IPV4(UpnpLib *p) { UpnpString_clear(p->m_gIF_IPV4); }

const UpnpString *UpnpLib_get_gIF_IPV4_NETMASK(const UpnpLib *p)
{
        return p->m_gIF_IPV4_NETMASK;
}

int UpnpLib_set_gIF_IPV4_NETMASK(UpnpLib *p, const UpnpString *s)
{
        const char *q = UpnpString_get_String(s);

        return UpnpString_set_String(p->m_gIF_IPV4_NETMASK, q);
}

size_t UpnpLib_get_gIF_IPV4_NETMASK_Length(const UpnpLib *p)
{
        return UpnpString_get_Length(UpnpLib_get_gIF_IPV4_NETMASK(p));
}

const char *UpnpLib_get_gIF_IPV4_NETMASK_cstr(const UpnpLib *p)
{
        return UpnpString_get_String(UpnpLib_get_gIF_IPV4_NETMASK(p));
}

int UpnpLib_strcpy_gIF_IPV4_NETMASK(UpnpLib *p, const char *s)
{
        return UpnpString_set_String(p->m_gIF_IPV4_NETMASK, s);
}

int UpnpLib_strncpy_gIF_IPV4_NETMASK(UpnpLib *p, const char *s, size_t n)
{
        return UpnpString_set_StringN(p->m_gIF_IPV4_NETMASK, s, n);
}

void UpnpLib_clear_gIF_IPV4_NETMASK(UpnpLib *p)
{
        UpnpString_clear(p->m_gIF_IPV4_NETMASK);
}

const UpnpString *UpnpLib_get_gIF_IPV6(const UpnpLib *p)
{
        return p->m_gIF_IPV6;
}

int UpnpLib_set_gIF_IPV6(UpnpLib *p, const UpnpString *s)
{
        const char *q = UpnpString_get_String(s);

        return UpnpString_set_String(p->m_gIF_IPV6, q);
}

size_t UpnpLib_get_gIF_IPV6_Length(const UpnpLib *p)
{
        return UpnpString_get_Length(UpnpLib_get_gIF_IPV6(p));
}

const char *UpnpLib_get_gIF_IPV6_cstr(const UpnpLib *p)
{
        return UpnpString_get_String(UpnpLib_get_gIF_IPV6(p));
}

int UpnpLib_strcpy_gIF_IPV6(UpnpLib *p, const char *s)
{
        return UpnpString_set_String(p->m_gIF_IPV6, s);
}

int UpnpLib_strncpy_gIF_IPV6(UpnpLib *p, const char *s, size_t n)
{
        return UpnpString_set_StringN(p->m_gIF_IPV6, s, n);
}

void UpnpLib_clear_gIF_IPV6(UpnpLib *p) { UpnpString_clear(p->m_gIF_IPV6); }

unsigned UpnpLib_get_gIF_IPV6_PREFIX_LENGTH(const UpnpLib *p)
{
        return p->m_gIF_IPV6_PREFIX_LENGTH;
}

int UpnpLib_set_gIF_IPV6_PREFIX_LENGTH(UpnpLib *p, unsigned n)
{
        p->m_gIF_IPV6_PREFIX_LENGTH = n;

        return 1;
}

const UpnpString *UpnpLib_get_gIF_IPV6_ULA_GUA(const UpnpLib *p)
{
        return p->m_gIF_IPV6_ULA_GUA;
}

int UpnpLib_set_gIF_IPV6_ULA_GUA(UpnpLib *p, const UpnpString *s)
{
        const char *q = UpnpString_get_String(s);

        return UpnpString_set_String(p->m_gIF_IPV6_ULA_GUA, q);
}

size_t UpnpLib_get_gIF_IPV6_ULA_GUA_Length(const UpnpLib *p)
{
        return UpnpString_get_Length(UpnpLib_get_gIF_IPV6_ULA_GUA(p));
}

const char *UpnpLib_get_gIF_IPV6_ULA_GUA_cstr(const UpnpLib *p)
{
        return UpnpString_get_String(UpnpLib_get_gIF_IPV6_ULA_GUA(p));
}

int UpnpLib_strcpy_gIF_IPV6_ULA_GUA(UpnpLib *p, const char *s)
{
        return UpnpString_set_String(p->m_gIF_IPV6_ULA_GUA, s);
}

int UpnpLib_strncpy_gIF_IPV6_ULA_GUA(UpnpLib *p, const char *s, size_t n)
{
        return UpnpString_set_StringN(p->m_gIF_IPV6_ULA_GUA, s, n);
}

void UpnpLib_clear_gIF_IPV6_ULA_GUA(UpnpLib *p)
{
        UpnpString_clear(p->m_gIF_IPV6_ULA_GUA);
}

unsigned UpnpLib_get_gIF_IPV6_ULA_GUA_PREFIX_LENGTH(const UpnpLib *p)
{
        return p->m_gIF_IPV6_ULA_GUA_PREFIX_LENGTH;
}

int UpnpLib_set_gIF_IPV6_ULA_GUA_PREFIX_LENGTH(UpnpLib *p, unsigned n)
{
        p->m_gIF_IPV6_ULA_GUA_PREFIX_LENGTH = n;

        return 1;
}

unsigned UpnpLib_get_gIF_INDEX(const UpnpLib *p) { return p->m_gIF_INDEX; }

int UpnpLib_set_gIF_INDEX(UpnpLib *p, unsigned n)
{
        p->m_gIF_INDEX = n;

        return 1;
}

unsigned short UpnpLib_get_LOCAL_PORT_V4(const UpnpLib *p)
{
        return p->m_LOCAL_PORT_V4;
}

int UpnpLib_set_LOCAL_PORT_V4(UpnpLib *p, unsigned short n)
{
        p->m_LOCAL_PORT_V4 = n;

        return 1;
}

unsigned short UpnpLib_get_LOCAL_PORT_V6(const UpnpLib *p)
{
        return p->m_LOCAL_PORT_V6;
}

int UpnpLib_set_LOCAL_PORT_V6(UpnpLib *p, unsigned short n)
{
        p->m_LOCAL_PORT_V6 = n;

        return 1;
}

unsigned short UpnpLib_get_LOCAL_PORT_V6_ULA_GUA(const UpnpLib *p)
{
        return p->m_LOCAL_PORT_V6_ULA_GUA;
}

int UpnpLib_set_LOCAL_PORT_V6_ULA_GUA(UpnpLib *p, unsigned short n)
{
        p->m_LOCAL_PORT_V6_ULA_GUA = n;

        return 1;
}

const handle_table_t *UpnpLib_get_HandleTable(const UpnpLib *p)
{
        return &p->m_HandleTable;
}

handle_table_t *UpnpLib_getnc_HandleTable(UpnpLib *p)
{
        return &p->m_HandleTable;
}

int UpnpLib_set_HandleTable(UpnpLib *p, const handle_table_t *buf)
{
        p->m_HandleTable = *buf;

        return 1;
}

void UpnpLib_clear_HandleTable(UpnpLib *p)
{
        memset(&p->m_HandleTable, 0, sizeof(handle_table_t));
}

const doc_type_array_t *UpnpLib_get_gMediaTypeArray(const UpnpLib *p)
{
        return &p->m_gMediaTypeArray;
}

doc_type_array_t *UpnpLib_getnc_gMediaTypeArray(UpnpLib *p)
{
        return &p->m_gMediaTypeArray;
}

int UpnpLib_set_gMediaTypeArray(UpnpLib *p, const doc_type_array_t *buf)
{
        p->m_gMediaTypeArray = *buf;

        return 1;
}

void UpnpLib_clear_gMediaTypeArray(UpnpLib *p)
{
        memset(&p->m_gMediaTypeArray, 0, sizeof(doc_type_array_t));
}

const xml_alias_t *UpnpLib_get_gAliasDoc(const UpnpLib *p)
{
        return &p->m_gAliasDoc;
}

xml_alias_t *UpnpLib_getnc_gAliasDoc(UpnpLib *p) { return &p->m_gAliasDoc; }

int UpnpLib_set_gAliasDoc(UpnpLib *p, const xml_alias_t *buf)
{
        p->m_gAliasDoc = *buf;

        return 1;
}

void UpnpLib_clear_gAliasDoc(UpnpLib *p)
{
        memset(&p->m_gAliasDoc, 0, sizeof(xml_alias_t));
}

const ithread_mutex_t *UpnpLib_get_gWebMutex(const UpnpLib *p)
{
        return &p->m_gWebMutex;
}

ithread_mutex_t *UpnpLib_getnc_gWebMutex(UpnpLib *p) { return &p->m_gWebMutex; }

int UpnpLib_set_gWebMutex(UpnpLib *p, const ithread_mutex_t *buf)
{
        p->m_gWebMutex = *buf;

        return 1;
}

void UpnpLib_clear_gWebMutex(UpnpLib *p)
{
        memset(&p->m_gWebMutex, 0, sizeof(ithread_mutex_t));
}

const membuffer *UpnpLib_get_gDocumentRootDir(const UpnpLib *p)
{
        return &p->m_gDocumentRootDir;
}

membuffer *UpnpLib_getnc_gDocumentRootDir(UpnpLib *p)
{
        return &p->m_gDocumentRootDir;
}

int UpnpLib_set_gDocumentRootDir(UpnpLib *p, const membuffer *buf)
{
        p->m_gDocumentRootDir = *buf;

        return 1;
}

void UpnpLib_clear_gDocumentRootDir(UpnpLib *p)
{
        memset(&p->m_gDocumentRootDir, 0, sizeof(membuffer));
}

size_t UpnpLib_get_g_maxContentLength(const UpnpLib *p)
{
        return p->m_g_maxContentLength;
}

int UpnpLib_set_g_maxContentLength(UpnpLib *p, size_t n)
{
        p->m_g_maxContentLength = n;

        return 1;
}

int UpnpLib_get_g_UpnpSdkEQMaxLen(const UpnpLib *p)
{
        return p->m_g_UpnpSdkEQMaxLen;
}

int UpnpLib_set_g_UpnpSdkEQMaxLen(UpnpLib *p, int n)
{
        p->m_g_UpnpSdkEQMaxLen = n;

        return 1;
}

int UpnpLib_get_g_UpnpSdkEQMaxAge(const UpnpLib *p)
{
        return p->m_g_UpnpSdkEQMaxAge;
}

int UpnpLib_set_g_UpnpSdkEQMaxAge(UpnpLib *p, int n)
{
        p->m_g_UpnpSdkEQMaxAge = n;

        return 1;
}

int UpnpLib_get_UpnpSdkInit(const UpnpLib *p) { return p->m_UpnpSdkInit; }

int UpnpLib_set_UpnpSdkInit(UpnpLib *p, int n)
{
        p->m_UpnpSdkInit = n;

        return 1;
}

int UpnpLib_get_UpnpSdkClientRegistered(const UpnpLib *p)
{
        return p->m_UpnpSdkClientRegistered;
}

int UpnpLib_set_UpnpSdkClientRegistered(UpnpLib *p, int n)
{
        p->m_UpnpSdkClientRegistered = n;

        return 1;
}

int UpnpLib_get_UpnpSdkDeviceRegisteredV4(const UpnpLib *p)
{
        return p->m_UpnpSdkDeviceRegisteredV4;
}

int UpnpLib_set_UpnpSdkDeviceRegisteredV4(UpnpLib *p, int n)
{
        p->m_UpnpSdkDeviceRegisteredV4 = n;

        return 1;
}

int UpnpLib_get_UpnpSdkDeviceRegisteredV6(const UpnpLib *p)
{
        return p->m_UpnpSdkDeviceRegisteredV6;
}

int UpnpLib_set_UpnpSdkDeviceRegisteredV6(UpnpLib *p, int n)
{
        p->m_UpnpSdkDeviceRegisteredV6 = n;

        return 1;
}

const UpnpString *UpnpLib_get_gUpnpSdkNLSuuid(const UpnpLib *p)
{
        return p->m_gUpnpSdkNLSuuid;
}

int UpnpLib_set_gUpnpSdkNLSuuid(UpnpLib *p, const UpnpString *s)
{
        const char *q = UpnpString_get_String(s);

        return UpnpString_set_String(p->m_gUpnpSdkNLSuuid, q);
}

size_t UpnpLib_get_gUpnpSdkNLSuuid_Length(const UpnpLib *p)
{
        return UpnpString_get_Length(UpnpLib_get_gUpnpSdkNLSuuid(p));
}

const char *UpnpLib_get_gUpnpSdkNLSuuid_cstr(const UpnpLib *p)
{
        return UpnpString_get_String(UpnpLib_get_gUpnpSdkNLSuuid(p));
}

int UpnpLib_strcpy_gUpnpSdkNLSuuid(UpnpLib *p, const char *s)
{
        return UpnpString_set_String(p->m_gUpnpSdkNLSuuid, s);
}

int UpnpLib_strncpy_gUpnpSdkNLSuuid(UpnpLib *p, const char *s, size_t n)
{
        return UpnpString_set_StringN(p->m_gUpnpSdkNLSuuid, s, n);
}

void UpnpLib_clear_gUpnpSdkNLSuuid(UpnpLib *p)
{
        UpnpString_clear(p->m_gUpnpSdkNLSuuid);
}

#ifdef UPNP_ENABLE_OPEN_SSL
SSL_CTX *UpnpLib_get_gSslCtx(const UpnpLib *p) { return p->m_gSslCtx; }

int UpnpLib_set_gSslCtx(UpnpLib *p, SSL_CTX *n)
{
        p->m_gSslCtx = n;

        return 1;
}

#endif
const ithread_mutex_t *UpnpLib_get_LogMutex(const UpnpLib *p)
{
        return &p->m_LogMutex;
}

ithread_mutex_t *UpnpLib_getnc_LogMutex(UpnpLib *p) { return &p->m_LogMutex; }

int UpnpLib_set_LogMutex(UpnpLib *p, const ithread_mutex_t *buf)
{
        p->m_LogMutex = *buf;

        return 1;
}

void UpnpLib_clear_LogMutex(UpnpLib *p)
{
        memset(&p->m_LogMutex, 0, sizeof(ithread_mutex_t));
}

Upnp_LogLevel UpnpLib_get_LogLevel(const UpnpLib *p) { return p->m_LogLevel; }

int UpnpLib_set_LogLevel(UpnpLib *p, Upnp_LogLevel n)
{
        p->m_LogLevel = n;

        return 1;
}

FILE *UpnpLib_get_LogFp(const UpnpLib *p) { return p->m_LogFp; }

int UpnpLib_set_LogFp(UpnpLib *p, FILE *n)
{
        p->m_LogFp = n;

        return 1;
}

int UpnpLib_get_LogIsStderr(const UpnpLib *p) { return p->m_gLogIsStderr; }

int UpnpLib_set_LogIsStderr(UpnpLib *p, int n)
{
        p->m_gLogIsStderr = n;

        return 1;
}

int UpnpLib_get_SetLogWasCalled(const UpnpLib *p)
{
        return p->m_SetLogWasCalled;
}

int UpnpLib_set_SetLogWasCalled(UpnpLib *p, int n)
{
        p->m_SetLogWasCalled = n;

        return 1;
}

int UpnpLib_get_LogInitWasCalled(const UpnpLib *p)
{
        return p->m_LogInitWasCalled;
}

int UpnpLib_set_LogInitWasCalled(UpnpLib *p, int n)
{
        p->m_LogInitWasCalled = n;

        return 1;
}

char *UpnpLib_get_LogFileName(const UpnpLib *p) { return p->m_LogFileName; }

int UpnpLib_set_LogFileName(UpnpLib *p, char *n)
{
        p->m_LogFileName = n;

        return 1;
}
