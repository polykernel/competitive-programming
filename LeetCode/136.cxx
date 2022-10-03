/*
    Problem: 136. Single Number
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            res ^= nums[i];
        }

        return res;
    }
};
