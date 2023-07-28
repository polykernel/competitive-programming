/*
    Problem: 1696. Jump Game VI
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 100000;
    static const int INF = 0x3f3f3f3f;
    int dp[MAXN];
    deque<pair<int, int>> dq;

    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp, -INF, sizeof(dp));

        dp[0] = nums[0];
        dq.push_back({dp[0], 0});
        for (int i = 1; i < n; ++i) {
            dp[i] = dq.front().first + nums[i];
            if (i >= k) {
                if (dq.front().second == i-k) dq.pop_front();
            }
            while (!dq.empty() && dq.back().first <= dp[i]) dq.pop_back();
            dq.push_back({dp[i], i});
        }

        return dp[n-1];
    }
};
