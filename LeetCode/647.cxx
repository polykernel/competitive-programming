/*
    Problem: 647. Palindromic Substrings
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 1000;
    bool dp[MAXN][MAXN];
    int countSubstrings(string s) {
        int n = s.length();
        int total = 0;

        dp[0][0] = true;
        ++total;
        for (int i = 1; i < n; ++i) {
            if (s[i-1] == s[i]) {
                dp[i-1][i] = true;
                ++total;
            }
            dp[i][i] = true;
            ++total;
        }

        for (int i = 2; i < n; ++i) {
            for (int v = 0; v + i < n; ++v) {
                if (s[v] == s[v+i] && dp[v+1][v+i-1]) {
                    dp[v][v+i] = true;
                    ++total;
                }
            }
        }

        return total;
    }
};
