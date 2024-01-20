//
// Created by gels on 2024/1/13.
//
#include <stdio.h>
#include <iostream>
#include <unordered_map>

int main(int argc, char **argv)
{
    std::unordered_map<std::string, int> map;
    map.insert(std::make_pair("aa", 100));
    map.insert(std::make_pair("bb", 200));
    for(auto it=map.begin();it!=map.end();it++) {
        printf("map cell key=%s val=%d\n", it->first.c_str(), it->second);
    }
    auto fn = [](std::pair<std::string, int> it) {
        printf("map cell key=%s val=%d\n", it.first.c_str(), it.second);
    };
    std::for_each(map.begin(), map.end(), fn);
    return 0;
}