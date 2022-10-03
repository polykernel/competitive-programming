/*
    Problem: 70. Climbing Stairs
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int f = 1;
        int s = 1;

        for (int i = 2; i <= n; ++i) {
            s = s + f;
            f = s - f;
        }

        return s;
    }
};
