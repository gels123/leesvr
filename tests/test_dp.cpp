//
// Created by gels on 2024/1/20.
//动态规划测试
//假设我们有n种类型的物品，分别编号为1, 2...n。其中编号为i的物品价值为vi，它的重量为wi。为了简化问题，假定价值和重量都是整数值。现在，假设我们有一个背包，它能够承载的重量是Cap。现在，我们希望往包里装这些物品，使得包里装的物品价值最大化，那么我们该如何来选择装的东西呢？注意：每种物品只有一件，可以选择放或者不放。初始化数据为：n=5，w={2,2,6,5,4}，v={6,3,5,4,6}，Cap=10
//

#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

typedef struct sitem {
    int id;
    int weight;
    int worth;
} sitem;

int dp(sitem *items, int n, int& maxweight, vector<int>& vec) {
    int weight = 1;
    int worth = 0;
    for (int i=0; i<=n; ++i) {

    }
    for (int w = 1; w <= maxweight; ++w) {
        int maxval = 0;

        vec[w] = maxval;
    }
    return vec.at(maxweight);
}

int main(int argc, char** argv) {
    //一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 10 级的台阶总共有多少种跳法
    //要跳10级台阶，2种情况：先跳到8级再跳2 或先跳9级再跳1，即f(10) = f(9) + f(8)，即f(n) = f(n-1) + f(n-2)
    int nums[11] = {0};
    nums[1] = 1;
    nums[2] = 2;
    nums[3] = nums[2] + nums[1];//3
    nums[4] = nums[3] + nums[2];//3+2=5
    for (int i=3;i<=10;++i) {
        nums[i] = nums[i-1] + nums[i-2];
    }
    cout << "qinwa10=" << nums[10] << endl;

    //给你一个整数数组 nums ，找到其中最长严格递增子序列的长度. nums = [10,9,2,5,3,7,101,18]  长度为4
    //f(8) = max{f(7) + 1?, f(6) + 1?, ...}
    int array[8] = {10,9,2,5,3,7,101,18};
    int dp[8] = {0};
    int dpmax[8] = {0};
    dp[0] = 1;
    dpmax[0] = array[0];
    for (int i=1; i<8; ++i) {
        for (int j=i-1; j>=0; --j) {
            if (array[i] >= dpmax[j]) {
                int v = dp[j] + 1;
                if (v > dp[i]) {
                    dpmax[j] = array[i];
                    dp[i] = v;
                }
            } else if(dp[i] == 0) {
                dpmax[j] = array[i];
                dp[i] = dp[j];
            }
        }
    }
    cout << "paixu7=" << dp[7] << endl;


    sitem items[5] = {0};
    items[0] = {0, 2, 3};
    items[1] = {0, 1, 3};
    items[2] = {0, 3, 1};
    items[3] = {0, 2, 1};
    items[4] = {0, 2, 3};
    int maxweight = 5;
    auto vec = *new vector<int>(512, 0);
    cout << "items length=" << sizeof (items)/sizeof (sitem) << " maxweight=" << maxweight << " vec length=" << vec.size() << endl;


    return 0;
}