/*
    Problem: 433. Minimum Genetic Mutation
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[10];
    static constexpr int INF = 0x3f3f3f3f;

    int f(string& a, string& b) {
        int cnt = 0;

        for (int i = 0; i < 8 && cnt <= 1; ++i) {
            if (a[i] != b[i]) ++cnt;
        }

        return cnt == 1;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        memset(dp, INF, sizeof(dp));
        queue<int> q;

        int end_index = -1;

        for (int i = 0; i < (int)bank.size(); ++i) {
            if (f(start, bank[i])) {
                dp[i] = 1;
                q.push(i);
            }
            if (end == bank[i]) end_index = i;
        }

        while (!q.empty()) {
            auto c = q.front();
            q.pop();

            if (c == end_index) break;

            for (int i = 0; i < (int)bank.size(); ++i) {
                if (f(bank[i], bank[c]) && dp[i] == INF) {
                    dp[i] = dp[c] + 1;
                    q.push(i);
                }
            }
        }

        if (end_index == -1 || dp[end_index] == INF) return -1;
        else return dp[end_index];
    }
};
