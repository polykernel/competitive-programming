/*
    Problem: 189. Rotate Array
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int m = k % (int)nums.size();
        vector<int> tmp(nums.begin(), nums.end() - m);

        for (int i = 0; i < m; ++i) {
            nums[i] = nums[nums.size() - m + i];
        }

        for (int i = m; i < (int)nums.size(); ++i) {
            nums[i] = tmp[i-m];
        }
    }
};
