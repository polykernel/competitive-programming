/*
    Problem: 326. Power of Three
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        else return 1162261467 % n == 0;
    }
};
