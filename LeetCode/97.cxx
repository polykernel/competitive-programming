/*
    Problem: 97. Interleaving String
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 200;
    static const int MAXL = 100;
    bool dp[MAXN+1][MAXL+1];
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int t = s3.length();

        dp[0][0] = n + m == t;
        for (int i = 1; i <= t; ++i) {
            for (int j = max(0, i-n); j < i && j <= m; ++j) {
                if (s1[i-j-1] == s3[i-1]) dp[i][j] |= dp[i-1][j];
            }
            for (int j = 1; j <= i && j <= m; ++j) {
                if (s2[j-1] == s3[i-1]) dp[i][j] |= dp[i-1][j-1];
            }
        }

        return dp[t][m];
    }
};
