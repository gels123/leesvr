/**
 * 自定义信号处理
 */
#ifndef MYSIGNAL_H
#define MYSIGNAL_H
#pragma once
	
class MySignal  
{
public:
	MySignal() = delete;
	~MySignal() = delete;

public:
	//init signal
	static void InitSignal();
	//regist signal handler for a given signo
	static void SignalHandler(int signo);
	//dump the trace of the process.
	static void DumpTrace();
};
#endif