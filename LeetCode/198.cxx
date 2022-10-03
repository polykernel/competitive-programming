/*
    Problem: 198. House Robber
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 100;
    int dp[MAXN+1];
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp[1] = nums[0];

        for (int i = 1; i < n; ++i) {
            dp[i+1] = max(dp[i], dp[i-2] + nums[i]);
        }

        return dp[n];
    }
};
