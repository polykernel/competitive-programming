/*
    Problem: 509. Fibonacci Number
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fib(int n) {
        int s = 0;
        int f = 1;

        if (n <= 1) return n;

        for (int i = 2; i <= n; ++i) {
            f = f + s;
            s = f - s;
        }

        return f;
    }
};
