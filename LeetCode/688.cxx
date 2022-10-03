/*
    Problem: 688. Knight Probability in Chessboard
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 25;
    double dp[MAXN][MAXN][2];
    int dir[8][2] = {{1, 2}, {-1, 2}, {2, 1}, {-2, 1}, {-1, -2}, {1, -2}, {-2, -1}, {2, -1}};

    double knightProbability(int n, int k, int row, int column) {
        double ans = 0;
        dp[row][column][0] = 1;

        for (int j = 1; j <= k; ++j) {
            for (int i = 0; i < n; ++i) {
                for (int v = 0; v < n; ++v) {
                    dp[i][v][j % 2] = 0;
                    for (int z = 0; z < 8; ++z) {
                        int nx = i + dir[z][0];
                        int ny = v + dir[z][1];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            dp[i][v][j % 2] += dp[nx][ny][(j-1) % 2];
                        }
                    }

                    dp[i][v][j % 2] /= 8;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int v = 0; v < n; ++v) {
                ans += dp[i][v][k % 2];
            }
        }

        return ans;
    }
};
