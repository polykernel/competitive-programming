/*
    Problem: 62. Unique Paths
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 100;
    int dp[MAXN+1];
    int uniquePaths(int m, int n) {
        dp[1] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int v = 1; v <= n; ++v) {
                dp[v] += dp[v-1];
            }
        }

        return dp[n];
    }
};
