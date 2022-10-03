/*
    Problem: 695. Max Area of Island
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 50;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool vst[MAXN][MAXN];
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int v = 0; v < n; ++v) {
                if (grid[i][v] == 1 && !vst[i][v]) {
                    int count = 0;

                    vst[i][v] = true;
                    q.push({i, v});

                    while (!q.empty()) {
                        auto c = q.front();
                        q.pop();
                        ++count;

                        for (int k = 0; k < 4; ++k) {
                            int nx = c.first + dir[k][0];
                            int ny = c.second + dir[k][1];

                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vst[nx][ny] && grid[nx][ny] == 1) {
                                vst[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }

                    ans = max(ans, count);
                }
            }
        }

        return ans;
    }
};
