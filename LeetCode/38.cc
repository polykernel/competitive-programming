/*
    Problem: 38. Count and Say
    Diffuculty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 30;
    vector<pair<int, int>> dp[MAXN+1];
    string countAndSay(int n) {
        dp[1].push_back({1, 1});

        string res;

        for (int i = 2; i <= n; ++i) {
            for (const auto [cnt, v] : dp[i-1]) {
                if (!dp[i].empty() && dp[i][dp[i].size()-1].second == cnt) {
                    ++dp[i][dp[i].size()-1].first;
                }
                else {
                    dp[i].push_back({1, cnt});
                }

                if (cnt == v) {
                    ++dp[i][dp[i].size()-1].first;
                }
                else {
                    dp[i].push_back({1, v});
                }
            }
        }

        for (int i = 0; i < dp[n].size(); ++i) {
            res.append(std::string(dp[n][i].first, dp[n][i].second+'0'));
        }

        return res;
    }
};
