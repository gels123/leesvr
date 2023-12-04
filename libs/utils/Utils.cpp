// 工具类
// Created by gels on 2023/12/1.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Utils.h"

// 获取当前时间戳(s)
long Utils::getTimestamp()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec; // 秒
}

// 获取当前时间戳(ms)
long Utils::getTimestampMs()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000; // 毫秒
}