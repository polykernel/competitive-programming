/*
    Problem: 746. Min Cost Climbing Stairs
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 1000;
    int dp[MAXN+1];

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        return dp[n];
    }
};
