//
// Created by gels on 2024/1/20.
//动态规划测试
//假设我们有n种类型的物品，分别编号为1, 2...n。其中编号为i的物品价值为vi，它的重量为wi。为了简化问题，假定价值和重量都是整数值。现在，假设我们有一个背包，它能够承载的重量是Cap。现在，我们希望往包里装这些物品，使得包里装的物品价值最大化，那么我们该如何来选择装的东西呢？注意：每种物品只有一件，可以选择放或者不放。初始化数据为：n=5，w={2,2,6,5,4}，v={6,3,5,4,6}，Cap=10
//

#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

auto vec = *new vector<int>(1024, 0);

int dp(int *pweight, int* pworth, bool* flags, int n, int maxweight) {
    if (maxweight >= 1024) {
        return -1;
    }
    for (int w = 1; w <= maxweight; ++w) {
        int maxval = 0;

        vec[w] = maxval;
    }
    return vec.at(maxweight);
}

int main(int argc, char** argv) {

    return 0;
}