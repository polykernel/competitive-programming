/*
    Problem: 213. House Robber II
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 100;
    int dp[MAXN+1][3];
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        dp[1][0] = nums[1];
        for (int i = 2; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-2][0] + nums[i]);
        }

        dp[1][1] = nums[0];
        for (int i = 2; i < n; ++i) {
            dp[i][1] = max(dp[i-1][1], dp[i-2][1] + nums[i-1]);
        }

        dp[1][2] = nums[1];
        for (int i = 2; i < n-1; ++i) {
            dp[i][2] = max(dp[i-1][1], dp[i-2][2] + nums[i]);
        }

        return max({dp[n-1][0], dp[n-1][1], dp[n-2][2]});
    }
};
