/*
    Problem: 53. Maximum Subarray
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 100000;
    int dp[MAXN+1];
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        dp[0] = INT_MIN;

        for (int i = 0; i < n; ++i) {
            sum = max(nums[i], sum + nums[i]);
            dp[i+1] = max(dp[i], sum);
        }

        return dp[n];
    }
};
