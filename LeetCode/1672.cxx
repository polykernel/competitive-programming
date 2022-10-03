/*
    Problem: 1672. Richest Customer Wealth
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;

        for (int i = 0; i < (int)accounts.size(); ++i) {
            int wealth = 0;
            for (int v = 0; v < (int)accounts[i].size(); ++v) {
                wealth += accounts[i][v];
            }
            ans = max(ans, wealth);
        }

        return ans;
    }
};
