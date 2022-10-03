/*
    Problem: 935. Knight Dialer
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MODN = 1000000007;
    int dp[10];
    int tmp[10];
    int knightDialer(int n) {
        int ans = 0;

        for (int i = 0; i < 10; ++i) dp[i] = 1;

        for (int i = 2; i <= n; ++i) {
            memcpy(tmp, dp, sizeof(dp));
            dp[1] = (1LL * tmp[8] + tmp[6]) % MODN;
            dp[2] = (1LL * tmp[7] + tmp[9]) % MODN;
            dp[3] = (1LL * tmp[4] + tmp[8]) % MODN;
            dp[4] = (1LL * tmp[3] + tmp[9] + tmp[0]) % MODN;
            dp[5] = 0;
            dp[6] = (1LL * tmp[1] + tmp[7] + tmp[0]) % MODN;
            dp[7] = (1LL * tmp[2] + tmp[6]) % MODN;
            dp[8] = (1LL * tmp[1] + tmp[3]) % MODN;
            dp[9] = (1LL * tmp[2] + tmp[4]) % MODN;
            dp[0] = (1LL * tmp[4] + tmp[6]) % MODN;
        }

        for (int i = 0; i < 10; ++i) {
            ans = (1LL * ans + dp[i]) % MODN;
        }

        return ans;
    }
};
