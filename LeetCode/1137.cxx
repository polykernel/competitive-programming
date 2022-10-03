/*
    Problem: 1137. N-th Tribonacci Number
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int t = 0;
        int s = 1;
        int f = 1;

        if (n <= 1) return n;
        else if (n == 2) return 1;

        for (int i = 3; i <= n; ++i) {
            f = f + s + t;
            s = f - s - t;
            t = f - s - t;
        }

        return f;
    }
};
