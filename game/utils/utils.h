#ifndef UTILS_H
#define UTILS_H
#pragma once
	
class Utils  
{
public:
	Utils() = delete;
	~Utils() = delete;

public:
	//测试
	static int Test(int n, int m);
	//获取当前时间戳
	static int GetCurTime();
	//获取当天0点的时间戳
	static int GetHour0Time(int ti = 0);
};
#endif