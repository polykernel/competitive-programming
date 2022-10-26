/*
    Problem: 2009. Minimum Number of Operations to Make Array Continuous
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> idx;
    unordered_map<int, bool> vst;
    int minOperations(vector<int>& nums) {
        int n = (int)nums.size();
        int mx_range = 0;

        for (int i = 0; i < n; ++i) {
            if (vst.count(nums[i]) == 0) {
                vst[nums[i]] = true;
                idx.push_back(nums[i]);
            }
        }

        sort(idx.begin(), idx.end());

        int m = (int)idx.size();

        for (int i = 1, j = 1; j <= m; ++i) {
            while (j-1 < m && idx[j-1] <= idx[i-1] + n - 1) ++j;
            mx_range = max(mx_range, j - i);
        }

        return n - mx_range;
    }
};
