/*
    Problem: 629. K Inverse Pairs Array
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 1000;
    static const int MODN = 1000000007;
    int dp[MAXN+1][MAXN+1];

    int kInversePairs(int n, int k) {
        dp[0][0] = 1;

        for (int i = 1; i <= k; ++i) {
            dp[0][i] += dp[0][i-1];
        }

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (j - i < 0)
                    dp[i][j] = (1LL * dp[i][j-1] % MODN + 1LL * dp[i-1][j] % MODN) % MODN;
                else {
                    dp[i][j] = (1LL * dp[i][j-1] % MODN + 1LL * dp[i-1][j] - dp[i-1][j-i] + MODN) % MODN;
                }
            }
        }

        if (k > 0) return (1LL * dp[n][k] - dp[n][k-1] + MODN) % MODN;
        else return (1LL * dp[n][k]) % MODN;
    }
};
