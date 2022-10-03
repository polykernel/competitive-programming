/*
    Problem: 740. Delete and Earn
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 10000;
    int dp[MAXN+1];
    int freq[MAXN+1];

    int deleteAndEarn(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] > mx) mx = nums[i];
            ++freq[nums[i]];
        }

        dp[1] = freq[1];
        for (int i = 2; i <= mx; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + freq[i] * i);
        }

        return dp[mx];
    }
};
