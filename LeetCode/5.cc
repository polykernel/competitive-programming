/*
    Problem: 5. Longest Palindromic Substring
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 1000;
    bool dp[MAXN][MAXN];
    string longestPalindrome(string s) {
        int n = s.length();
        int ml = 1;
        int sp = 0;

        dp[0][0] = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) {
                dp[i-1][i] = true;
                sp = i-1;
                ml = 2;
            }
            dp[i][i] = true;
        }

        for (int i = 2; i < n; ++i) {
            for (int v = 0; v + i < n; ++v) {
                if (s[v] == s[v+i] && dp[v+1][v+i-1]) {
                    dp[v][v+i] = true;
                    if (i+1 > ml) {
                        sp = v;
                        ml = i+1;
                    }
                }
            }
        }

        return s.substr(sp, ml);
    }
};
