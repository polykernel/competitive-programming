/*
    Problem: 1615. Maximal Network Rank
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static constexpr int MAXN = 100;
    bool adj[MAXN][MAXN];
    int deg[MAXN];
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;

        for (int i = 0; i < (int)roads.size(); ++i) {
            int u = roads[i][0];
            int v = roads[i][1];

            ++deg[u];
            ++deg[v];

            adj[u][v] = adj[v][u] = true;
        }

        for (int i = 0; i < n; ++i) {
            for (int v = i+1; v < n; ++v) {
                ans = max(ans, deg[i] + deg[v] - adj[i][v]);
            }
        }

        return ans;
    }
};
