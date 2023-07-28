/*
    Problem: 78. Subsets
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> log_2;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> res;

        res.reserve(1 << n);

        for (int i = 0; i < n; ++i) {
            log_2[1 << i] = i;
        }

        for (int i = 0; i < 1 << n; ++i) {
            vector<int> cset;

            for (int j = i; j > 0; j = j & (j-1)) {
                cset.push_back(nums[log_2[j & -j]]);
            }

            res.push_back(cset);
        }

        return res;
    }
};
