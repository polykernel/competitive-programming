/*
    Problem: 2320. Count Number of Ways to Place Houses
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 10000;
    static const int MODN = 1000000007;
    int dp[MAXN+1];
    int countHousePlacements(int n) {
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i <= n; ++i) {
            dp[i] = (1LL * dp[i-1] % MODN + dp[i-2] % MODN) % MODN;
        }

        return (1LL * dp[n] * dp[n]) % MODN;
    }
};
