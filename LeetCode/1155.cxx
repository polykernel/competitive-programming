/*
    Problem: 1155. Number of Dice Rolls With Target Sum
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MODN = 1000000007;
    static const int MAXN = 30;
    static const int MAXT = 1000;
    int dp[MAXN+1][MAXT+1];

    int numRollsToTarget(int n, int k, int target) {
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(n*k, target); ++j) {
                for (int w = 1; w <= min(j, k); ++w) {
                    dp[i][j] = (1LL*dp[i][j] % MODN + 1LL*dp[i-1][j-w] % MODN) % MODN;
                }
            }
        }

        return dp[n][target];
    }
};
