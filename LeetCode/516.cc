/*
    Problem: 516. Longest Palindromic Subsequence
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 1000;
    int dp[MAXN][MAXN];
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        dp[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) dp[i-1][i] = 2;
            else dp[i-1][i] = 1;
            dp[i][i] = 1;
        }

        for (int i = 2; i < n; ++i) {
            for (int v = 0; v + i < n; ++v) {
                if (s[v] == s[v+i]) dp[v][v+i] = dp[v+1][v+i-1] + 2;
                dp[v][v+i] = max(dp[v][v+i], max(dp[v+1][v+i], dp[v][v+i-1]));
            }
        }

        return dp[0][n-1];
    }
};
