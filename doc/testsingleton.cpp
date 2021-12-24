//
// Created by gels on 2021/12/24.
//
// rm -rf *.o *.out
// g++ -o testsingleton.out -std=c++11 testsingleton.cpp

#include <stdio.h>
#include <iostream>
#include <memory>
#include "../lib/base/Singleton.h"

class PathFinder : public Singleton<PathFinder>
{
public:
    PathFinder() {
        printf("PathFinder::PathFinder\n");
    };
    ~PathFinder() {
        printf("PathFinder::~PathFinder\n");
    };
};

int main(int arg, char **args)
{
    {
        std::shared_ptr<PathFinder> ptr = PathFinder::GetInstance();
//        std::shared_ptr<Singleton> ptr = Singleton<Singleton>::GetInstance();
    }

    return 0;
}