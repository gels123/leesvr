// 信号处理类
// Created by gels on 2023/12/1.
//
#ifndef MYSIGNAL_H
#define MYSIGNAL_H


class Signal
{
public:
	Signal() = delete;
	~Signal() = delete;

public:
	//init signal
	static void InitSignal();
	//regist signal handler for a given signo
	static void SignalHandler(int signo);
	//dump the trace of the process.
	static void DumpTrace();
};


#endif