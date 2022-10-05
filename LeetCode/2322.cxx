/*
    Problem: 2322. Minimum Score After Removals on a Tree
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 1000;
    static const int LOG = 11;
    vector<int> adj[MAXN];
    int xsum[MAXN];
    int depth[MAXN];
    int anc[LOG][MAXN];

    void dfs(int u, int p) {
        depth[u] = depth[p] + 1;
        anc[0][u] = p;

        for (int i = 1; i < LOG; ++i) {
            anc[i][u] = anc[i-1][anc[i-1][u]];
        }
        for (const auto& v : adj[u]) {
            if (v != p) {
                dfs(v, u);
                xsum[u] ^= xsum[v];
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int k = LOG-1; k >= 0; --k) {
            if (depth[anc[k][u]] >= depth[v]) u = anc[k][u];
        }

        if (u == v) return u;

        for (int k = LOG-1; k >= 0; --k) {
            if (anc[k][u] != anc[k][v]) {
                u = anc[k][u];
                v = anc[k][v];
            }
        }

        return anc[0][u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int ans = 0x3f3f3f3f;
        vector<int> xs(3);

        for (int i = 0; i < n; ++i) {
            xsum[i] = nums[i];
        }

        for (int i = 0; i < n-1; ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        depth[0] = -1;
        dfs(0, 0);

        for (int i = 0; i < n-1; ++i) {
            for (int v = i+1; v < n-1; ++v) {
                int a, b, c, d;
                a = edges[i][0];
                b = edges[i][1];
                c = edges[v][0];
                d = edges[v][1];

                if (depth[a] > depth[b]) swap(a, b);
                if (depth[c] > depth[d]) swap(c, d);

                int ll = lca(b, d);

                if (ll != b && ll != d) {
                    xs[0] = xsum[b];
                    xs[1] = xsum[d];
                    xs[2] = xsum[0] ^ xsum[b] ^ xsum[d];
                }
                else {
                    if (depth[a] > depth[c]) {
                        xs[0] = xsum[0] ^ xsum[d];
                        xs[1] = xsum[d] ^ xsum[b];
                        xs[2] = xsum[b];
                    }
                    else {
                        xs[0] = xsum[0] ^ xsum[b];
                        xs[1] = xsum[b] ^ xsum[d];
                        xs[2] = xsum[d];
                    }
                }

                sort(xs.begin(), xs.end());

                ans = min(ans, xs[2] - xs[0]);
            }
        }

        return ans;
    }
};
