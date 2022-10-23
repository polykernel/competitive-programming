/*
    Problem: 645. Set Mismatch
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 10000;
    int freq[MAXN+1];
    vector<int> findErrorNums(vector<int>& nums) {
        int xsum = 0;
        int d;

        for (int i = 0; i < (int)nums.size(); ++i) {
            xsum ^= (i+1) ^ nums[i];
            if (freq[nums[i]] == 1) d = nums[i];
            ++freq[nums[i]];
        }

        return {d, xsum ^ d};
    }
};
