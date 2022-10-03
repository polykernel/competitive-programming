/*
    Problem: 463. Island Perimeter
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 100;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool vst[MAXN][MAXN];
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;
        bool flag = false;

        for (int i = 0; i < m && !flag; ++i) {
            for (int v = 0; v < n && !flag; ++v) {
                if (grid[i][v] == 1 && !vst[i][v]) {
                    vst[i][v] = true;
                    q.push({i, v});

                    while (!q.empty()) {
                        auto c = q.front();
                        q.pop();

                        for (int k = 0; k < 4; ++k) {
                            int nx = c.first + dir[k][0];
                            int ny = c.second + dir[k][1];

                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                                if (!vst[nx][ny]) {
                                    vst[nx][ny] = true;
                                    q.push({nx, ny});
                                }
                            }
                            else {
                               ++perimeter;
                            }
                        }
                    }

                    flag = true;
                }
            }
        }

        return perimeter;
    }
};
