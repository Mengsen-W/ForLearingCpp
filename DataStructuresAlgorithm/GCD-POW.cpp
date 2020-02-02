/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-24 17:24:42
 * @Last Modified by:   Mengsen.Wang
 * @Last Modified time: 2020-01-24 17:24:42
 */
#include <iostream>
bool isEven(long long);

long long gcd(long long m, long long n) {
    /**
     * 欧几里得算法, 得到两个整数的最大公因数
     * 如果 M > N, 则 M mod N < M/2
     * 时间复杂度 O(logN)
    */
    while(n != 0) {
        long long rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

long long pow (long long x, int n){
    /**
     * 二分求一个整数的整数幂
     * 时间复杂度为 O(logN)
    */
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    if(isEven(n))
        return pow (x * x, n / 2);
    else
        return pow (x * x, n / 2) * x;
}

bool isEven(long long x) {
    if(x % 2 == 0)
        return true;
    else
        return false;
}

int main () {
    long long n1 = 1989;
    long long n2 = 1590;
    long long g = 0;
    g = gcd (n1, n2);
    std::cout << g <<std::endl;
    long long x = 2;
    int n = 62;
    long long r = 0;
    r = pow(x, n);
    std::cout << r <<std::endl;
    return 0;
}