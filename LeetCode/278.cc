/*
    Problem: 278. First Bad Version
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        for (int i = 31 - __builtin_clz(n); i >= 0; --i) {
            if (isBadVersion(n-(1 << i))) {
                n -= (1 << i);
            }
        }

        return n;
    }
};
