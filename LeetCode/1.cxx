/*
    Problem: 1. Two Sum
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> idx;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (idx.count(target - nums[i]) != 0) {
                res[0] = i;
                res[1] = idx[target - nums[i]];
                break;
            }
            idx[nums[i]] = i;
        }

        return res;
    }
};
