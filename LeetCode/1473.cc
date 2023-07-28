/*
    Problem: 1473. Paint House III
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXM = 100;
    static const int MAXN = 20;
    static const int INF = 0x3f3f3f3f;
    int dp[MAXM+1][MAXM+1][MAXN+1];

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, INF, sizeof(dp));

        int ans = INF;

        for (int i = 1; i <= n; ++i) {
            dp[0][0][i] = 0;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (houses[i-1] > 0) {
                    int v = houses[i-1];
                    dp[i][j][v] = dp[i-1][j][v];
                    for (int k = 1; k <= n; ++k) {
                        if (k == v) continue;
                        dp[i][j][v] = min(dp[i][j][v], dp[i-1][j-1][k]);
                    }
                }
                else {
                    for (int v = 1; v <= n; ++v) {
                        dp[i][j][v] = min(dp[i][j][v], dp[i-1][j][v] + cost[i-1][v-1]);
                        for (int k = 1; k <= n; ++k) {
                            if (k == v) continue;
                            dp[i][j][v] = min(dp[i][j][v], dp[i-1][j-1][k] + cost[i-1][v-1]);
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            ans = min(ans, dp[m][target][i]);
        }

        return ans == INF ? -1 : ans;
    }
};
