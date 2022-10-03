/*
    Problem: 552. Student Attendance Record II
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MODN = 1000000007;
    int dp[2][3];
    int tmp[2][3];

    int checkRecord(int n) {
        int ans = 0;

        dp[1][0] = dp[0][1] = dp[0][0] = 1;

        for (int i = 2; i <= n; ++i) {
            memcpy(tmp, dp, sizeof(dp));
            dp[1][0] = (1LL * tmp[1][0] + tmp[1][1] + tmp[1][2] + tmp[0][0] + tmp[0][1] + tmp[0][2]) % MODN;
            dp[0][0] = (1LL * tmp[0][0] + tmp[0][1] + tmp[0][2]) % MODN;
            dp[1][1] = tmp[1][0];
            dp[1][2] = tmp[1][1];
            dp[0][1] = tmp[0][0];
            dp[0][2] = tmp[0][1];
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                ans = (1LL * ans + dp[i][j]) % MODN;
            }
        }

        return ans;
    }
};
