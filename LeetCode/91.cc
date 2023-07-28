/*
    Problem: 91. Decode ways
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 100;
    int dp[MAXN+1];
    int numDecodings(string s) {
        dp[0] = 1;
        dp[1] = s[0] > '0' ? 1 : 0;
        for (int i = 2; i <= (int)s.length(); ++i) {
            bool f = true;
            bool v = true;
            if (s[i-2] > '2' || s[i-2] == '0') f = false;
            if (s[i-2] == '2' && s[i-1] > '6') f = false;
            if (s[i-1] == '0') v = false;

            if (f && v) dp[i] = dp[i-1] + dp[i-2];
            else if (f) dp[i] = dp[i-2];
            else if (v) dp[i] = dp[i-1];
            else dp[i] = 0;
        }

        return dp[(int)s.length()];
    }
};
