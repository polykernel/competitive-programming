/*
    Problem: 300. Longest Increasing Subsequence
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> s;
        s.push_back(nums[0]);

        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] > s.back()) {
                s.push_back(nums[i]);
            }
            else {
                auto it = lower_bound(s.begin(), s.end(), nums[i]);
                *it = nums[i];
            }
        }

        return (int)s.size();
    }
};
