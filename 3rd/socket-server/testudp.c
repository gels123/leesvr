#include "socket_server.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void * _poll(void * ud) {
    printf("===== _poll =====\n");
	struct socket_server *ss = ud;
	struct socket_message result;
	for (;;) {
		int type = socket_server_poll(ss, &result, NULL);
        printf("_poll for type=%d\n", type);
		// DO NOT use any ctrl command (socket_server_close, etc.) in this thread.
		switch (type) {
		case SOCKET_EXIT:
			return NULL;
		case SOCKET_DATA:
			printf("message tcp (%lu) [id=%d] size=%d data=%s\n", result.opaque, result.id, result.ud, result.data);
			free(result.data);
			break;
		case SOCKET_CLOSE:
			printf("close(%lu) [id=%d]\n",result.opaque,result.id);
			break;
		case SOCKET_OPEN:
			printf("open(%lu) [id=%d] %s\n",result.opaque,result.id,result.data);
			break;
		case SOCKET_ERROR:
			printf("error(%lu) [id=%d]\n",result.opaque,result.id);
			break;
		case SOCKET_ACCEPT:
			printf("accept(%lu) [id=%d %s] from [%d]\n",result.opaque, result.ud, result.data, result.id);
			break;
		case SOCKET_UDP:
			printf("message tcp (%lu) [id=%d] size=%d data=%s\n", result.opaque, result.id, result.ud, result.data);
			free(result.data);
			break;
		}
	}
}

int main(int argc, char** argv) {
	//linux下给disconnected socket发送消息，底层会抛出SIGPIPE信号，这个信号的缺省处理是进程退出，忽略之
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sigaction(SIGPIPE, &sa, 0);

	struct socket_server* ss = socket_server_create();

    char addr[64] = "0.0.0.0";
    int port  = 9999;
    int l = socket_server_udp(ss, port, addr, port);
    if(-1 == l){
        printf("sockect udp listen failed, addr=%s port=%d\n", addr, port);
        return 0;
    }

    pthread_t pid;
	pthread_create(&pid, NULL, _poll, ss);

	printf("sockect udp listening %s:%d l=%d\n", addr, port, l);

	// socket_server_exit(ss);

	pthread_join(pid, NULL);

	socket_server_release(ss);

	return 0;
}
