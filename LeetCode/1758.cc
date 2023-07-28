/*
    Problem: 1758. Minimum Changes To Make Alternating Binary String
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[2];
    int minOperations(string s) {
        int n = s.length();

        if (s[0] == '0') {
            dp[1] = 1;
            dp[0] = 0;
        }
        else {
            dp[0] = 1;
            dp[1] = 0;
        }

        for (int i = 1; i < n; ++i) {
            int t = dp[0];
            if (s[i] == '0') {
                dp[0] = dp[1];
                dp[1] = t + 1;
            }
            else {
                dp[0] = dp[1] + 1;
                dp[1] = t;
            }
        }

        return min(dp[0], dp[1]);
    }
};
