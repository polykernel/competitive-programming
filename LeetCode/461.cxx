/*
    Problem: 461. Hamming Distance
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int xp = x ^ y;

        for (int i = 0; i < 31; ++i) {
            if (xp & (1 << i)) {
                ++count;
            }
        }

        return count;
    }
};
