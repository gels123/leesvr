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
	//dump the trace of the process.
	static void DumpTrace();
	//regist new signal handler for a given signo
	static void SignalHandler(int signo);
};
#endif