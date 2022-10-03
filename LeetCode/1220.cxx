/*
    Problem: 1220. Count Vowels Permutation
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MODN = 1000000007;
    int dp[5];

    int countVowelPermutation(int n) {
        dp[0] = dp[1] = dp[2] = dp[3] = dp[4] = 1;
        for (int j = 2; j <= n; ++j) {
            int a = dp[0];
            int e = dp[1];
            int i = dp[2];
            int o = dp[3];
            int u = dp[4];
            dp[0] = (1LL * e + u + i) % MODN;
            dp[1] = (1LL * a + i) % MODN;
            dp[2] = (1LL * e + o) % MODN;
            dp[3] = 1LL * i % MODN;
            dp[4] = (1LL * i + o) % MODN;
        }

        return (1LL * dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) % MODN;
    }
};
