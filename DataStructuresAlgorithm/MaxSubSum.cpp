/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-24 07:37:33
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-24 14:10:23
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int maxSubSum1(const vector<int> & a) {
    /**
     * i 用来遍历每一个数
     * j, k 用来遍历每一个数后面的每一种个数的情况
     * 复杂度 O(N^3)
    */
    int maxSum = 0;
    for(int i = 0; i < a.size(); ++i) {
        for(int j =i; j < a.size(); ++j) {
            int thisSum = 0;

            for(int k = i; k <= j; ++k) {
                thisSum += a[k];

                if(thisSum > maxSum) {
                    maxSum = thisSum;
                }
            }
        }
    }
    return maxSum;
}

int maxSubSum2(const vector<int> &a) {
    /**
     * 采用优化的遍历算法
     * 复杂度 O(N^2)
    */

    int maxSum = 0;
    for(int i =0; i < a.size(); ++i) {
        int thisSum = 0;
        for(int j = i; j < a.size(); ++j) {
            thisSum += a [j];

            if(thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int maxSumRec(const vector<int> & a,int left, int right){
    if(left == right) {
        if (a[left] > 0 )
            return a[left];
        else
            return -1;
    }
    int center = (left + right) / 2;
    int maxLeftSum = maxSumRec(a, left, center);
    int maxRightSum = maxSumRec(a, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum =0;
    for(int i = center; i >= left; --i){
        leftBorderSum += a[i];
        if(leftBorderSum > maxLeftBorderSum)
        maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for(int j = center + 1; j <= right; ++j){
        rightBorderSum += a[j];
        if(rightBorderSum > maxRightBorderSum)
        maxRightBorderSum = rightBorderSum;
    }

    return (max ( max(maxLeftSum, maxRightSum), maxLeftBorderSum + maxRightBorderSum));
}

int maxSubSum3(vector<int> &a) {
    /**
     * 采用分治的算法
     * 复杂度为 O(N log N)
    */
    return maxSumRec(a, 0, a.size() - 1);
}

int maxSubSum4(const vector<int> &a){
    /**
     * 线性时间最大相连子序列和算法
     * 算法复杂度 O(N)
    */
    int maxSum = 0, thisSum = 0;

    for(int i = 0; i < a.size(); ++i){
        thisSum += a[i];

        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}


int main() {
    vector<int> a = {15, 10, -9, -5, 1, 0, -8, 9};
    int maxSum = 0;
    // maxSum = maxSubSum1(a);
    // maxSum = maxSubSum2(a);
    // maxSum = maxSubSum3(a);
    maxSum = maxSubSum4(a);

    cout << maxSum << endl;
    return 0;
}