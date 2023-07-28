/*
    Problem: 693. Binary Number with Alternating Bits
    Diffuculty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long bpow[17];
    bool hasAlternatingBits(int n) {
        // a number that has its bit alternating in binary is either a sum
        // of powers of 4 that is 1 + 4 + 4^2 + 4^3, or 2 times said sum
        // corresponding to ...1010101 and ...01010 respectively.
        // if n is odd, then it can only be a sum of powers of 4 since 1 is odd
        // and all other terms in the geometric series is even.
        // if n is even, then n/2 must be odd and satisify the above condition
        if (n % 2 == 0) n /= 2;

        int l = 0;
        int h = 16;

        // compute powers of 4
        bpow[0] = 1;
        for (int i = 1; i <= 16; ++i) bpow[i] = bpow[i-1] * 4;

        while (l <= h) {
            int m = l+(h-l)/2;
            int s = 1LL*(bpow[m]-1)/3;
            if (n == s) return true;
            else if (n > s) l = m + 1;
            else h = m - 1;
        }

        return false;
    }
};
