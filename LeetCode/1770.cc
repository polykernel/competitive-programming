/*
    Problem: 1770. Maximum Score from Performing Multiplication Operations
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXM = 1000;
    // state: dp[first i operations][taking first j elements]
    // transition: dp[i][j] <- max(dp[i-1][j-1] + nums[j-1] * multipliers[i-1], dp[i-1][j] + nums[m-(i-j)] * multipliers[i-1])
    int dp[MAXM+1][MAXM+1];
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        int ans = INT_MIN;

        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i-1][0] + nums[n-i] * multipliers[i-1];
            dp[i][i] = dp[i-1][i-1] + nums[i-1] * multipliers[i-1];
            for (int j = 1; j < i; ++j) {
                dp[i][j] = max(dp[i-1][j-1] + nums[j-1] * multipliers[i-1], dp[i-1][j] + nums[n-(i-j)] * multipliers[i-1]);
            }
        }

        for (int j = 0; j <= m; ++j) {
            if (dp[m][j] > ans) ans = dp[m][j];
        }

        return ans;
    }
};
