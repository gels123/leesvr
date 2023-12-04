// 工具类
// Created by gels on 2023/12/1.
//

#ifndef LEESVR_UTILS_H
#define LEESVR_UTILS_H


class Utils {
public:
    Utils() = delete;
    ~Utils() = delete;

public:
    // 获取当前时间戳(s)
    static long getTimestamp();
    // 获取当前时间戳(ms)
    static long getTimestampMs();
};


#endif //LEESVR_UTILS_H
