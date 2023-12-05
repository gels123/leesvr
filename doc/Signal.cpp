#include "Signal.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Signal.h"        /* for signal */
#include <execinfo.h> 	/* for backtrace() */
	
#define BACKTRACE_SIZE 16

void Signal::InitSignal()
{
	struct sigaction sa;
	sa.sa_flags = 0;
	sa.sa_handler = Signal::SignalHandler;
	sigemptyset(&sa.sa_mask);
	// 程序异常终止
	sigaction(SIGABRT, &sa, NULL);
    // 非法访问存储器, 如访问不存在的内存单元
	sigaction(SIGSEGV, &sa, NULL);
    // 算术运算出错, 如除数为0或溢出
	sigaction(SIGFPE, &sa, NULL);
    // 非法函数映象，如非法指令
	sigaction(SIGILL, &sa, NULL);
    // 中断信号终止进程, 如 ctrl-C
	sigaction(SIGINT, &sa, NULL);
    // 软件终止信号, 终止进程
	sigaction(SIGTERM, &sa, NULL);
	// 建立CORE文件终止进程, 并且生成core文件
	sigaction(SIGQUIT, &sa, NULL);
	// 文件长度过长终止进程
	sigaction(SIGXFSZ, &sa, NULL);
	// 总线错误, 建立CORE文件
	sigaction(SIGBUS, &sa, NULL);
	// 跟踪自陷, 建立CORE文件
	sigaction(SIGTRAP, &sa, NULL);
	// 向一个没有读进程的管道写数据, 终止进程
	sigaction(SIGPIPE, &sa, NULL);
	// 非终端来的停止信号, 终止进程
	sigaction(SIGSTOP, &sa, NULL);
	// 终端来的停止信号, 终止进程
	sigaction(SIGTSTP, &sa, NULL);
	// 终端线路挂断终止进程
	sigaction(SIGHUP, &sa, NULL);
	// 后台进程写终端, 终止进程
	sigaction(SIGTTOU, &sa, NULL);
	// 后台进程读终端, 终止进程
	sigaction(SIGTTIN, &sa, NULL);
}
 
void Signal::SignalHandler(int signo)
{
	switch(signo) {
		case SIGABRT:
		case SIGSEGV:
		case SIGFPE:
		case SIGILL:
		case SIGINT:
		case SIGTERM:
		case SIGQUIT:
		case SIGXFSZ:
		case SIGBUS:
		case SIGTRAP:
		case SIGPIPE:
		case SIGSTOP:
		case SIGTSTP:
		case SIGHUP:
		case SIGTTOU:
		case SIGTTIN: {
			printf("==Dump address maps start==\n");
			char buff[64] = {0x00};
			sprintf(buff,"cat /proc/%d/maps", getpid());
			system((const char*) buff);
			printf("==Dump address maps end==\n");

			printf("\n========= Signal::SignalHandler catch signal %d =========\n", signo);
			printf("==Dump stack start==\n");
			Signal::DumpTrace();
			printf("==Dump stack end==\n");
			
			//recover using default signal action, old code: signal(signo, SIG_DFL)
			struct sigaction sa;
			sa.sa_flags = 0;
			sa.sa_handler = SIG_DFL; //recover using default signal action
			sigemptyset(&sa.sa_mask);
			sigaction(signo, &sa, NULL);
			
			raise(signo); //re-raise the signal
			break;
		}
		default: {
			printf("Signal::SignalHandler not deal signal %d\n", signo);
			break;
		}
	}
}

void Signal::DumpTrace()
{
	int j, nptrs;
	void *buffer[BACKTRACE_SIZE];
	char **strings;
	
	nptrs = backtrace(buffer, BACKTRACE_SIZE);
	
	printf("backtrace() returned %d addresses\n", nptrs);
 
	strings = backtrace_symbols(buffer, nptrs);
	if (strings == NULL) {
		perror("backtrace_symbols");
		exit(EXIT_FAILURE);
	}
 
	for (j = 0; j < nptrs; j++)
		printf("  [%02d] %s\n", j, strings[j]);
 
	free(strings);
}