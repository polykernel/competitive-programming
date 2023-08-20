/*
    Problem: 2830. Maximize the Profit as the Salesman
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    constexpr static int MAXN = 100000;
    int dp[MAXN+2];
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        std::sort(offers.begin(), offers.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[1] == b[1]) return a[0] < b[0];
            else return a[1] < b[1];
        });
        dp[0] = 0;
        int l = 0;
        int m = offers.size();

        // TODO: refactor logic to be less ad-hoc
        for (int i = 0; i < n; i++) {
            while (l < m && offers[l][1] < i) ++l;
            dp[i+1] = std::max(dp[i], dp[i+1]);
            while (l < m && offers[l][1] == i) {
                dp[i+1] = std::max(dp[i+1], dp[offers[l][0]] + offers[l][2]);
                ++l;
            }
        }
        
        return dp[n];
    }
};
