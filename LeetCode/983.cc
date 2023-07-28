/*
    Problem: 983. Minimum Cost For Tickets
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXD = 365;
    static const int INF = 0x3f3f3f3f;
    int dp[MAXD+1];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;

        for (int i = 1; i <= (int)days.size(); ++i) {
            if (days[i-1] <= 1) {
                dp[i] = min(dp[i], costs[0] + dp[0]);
            }
            else {
                dp[i] = min(dp[i], costs[0] + dp[i-1]);
            }
            if (days[i-1] <= 7) {
                dp[i] = min(dp[i], costs[1] + dp[0]);
            }
            else {
                int prev = upper_bound(days.begin(), days.end(), days[i-1] - 7) - days.begin();
                dp[i] = min(dp[i], costs[1] + dp[prev]);
            }
            if (days[i-1] <= 30) {
                dp[i] = min(dp[i], costs[2] + dp[0]);
            }
            else {
                int prev = upper_bound(days.begin(), days.end(), days[i-1] - 30) - days.begin();
                dp[i] = min(dp[i], costs[2] + dp[prev]);
            }
        }

        return dp[(int)days.size()];
    }
};
