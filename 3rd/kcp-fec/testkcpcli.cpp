#include <unistd.h>
#include <sys/time.h>
#include <cstring>
#include <cstdio>
#include <pthread.h>
#include "socketsessionudp.h"

IUINT32 iclock();

int main() {
    struct timeval time;
    gettimeofday(&time, NULL);
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000));

    SocketSessionUdp *serverUdp = SocketSessionUdp::DialWithOptions("127.0.0.1", 9999, 2, 2);
    serverUdp->NoDelay(1, 20, 2, 1);
    serverUdp->WndSize(128, 128);
    serverUdp->SetMtu(1400);
    serverUdp->SetStreamMode(true);
    serverUdp->SetDSCP(46);

    assert(serverUdp != nullptr);
    ssize_t nsent = 0;
    ssize_t nrecv = 0;
    char *buf = (char *) malloc(128);

    for (int i = 0; i < 10; i++) {
        sprintf(buf, "message:%d", i);
        printf("main for i=%d buf=%s\n", i, buf);
        auto sz = strlen(buf);
        serverUdp->Write(buf, sz);
        serverUdp->Update(iclock());
        memset(buf, 0, 128);
        ssize_t n = 0;
        do {
            printf("loop i=%d\n", i);
            n = serverUdp->Read(buf, 128);
            if (n > 0) {
                printf("===Read=%s\n", buf);
            }
            usleep(33000);
            serverUdp->Update(iclock());
        } while(n==0);
    }

    SocketSessionUdp::Destroy(serverUdp);
}


void
itimeofday(long *sec, long *usec) {
    struct timeval time;
    gettimeofday(&time, NULL);
    if (sec) *sec = time.tv_sec;
    if (usec) *usec = time.tv_usec;
}

IUINT64 iclock64(void) {
    long s, u;
    IUINT64 value;
    itimeofday(&s, &u);
    value = ((IUINT64) s) * 1000 + (u / 1000);
    return value;
}

IUINT32 iclock() {
    return (IUINT32) (iclock64() & 0xfffffffful);
}


