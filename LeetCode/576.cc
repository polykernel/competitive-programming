/*
    Problem: 576. Out of Boundary Paths
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 50;
    static const int MODN = 1000000007;
    int dp[MAXN][MAXN][2];
    int total[MAXN][MAXN];
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {//
        int ans = 0;
        if (maxMove == 0) return 0;
        dp[startRow][startColumn][0] = 1;
        total[startRow][startColumn] = 1;

        for (int j = 1; j < maxMove; ++j) {
            for (int i = 0; i < m; ++i) {
                for (int v = 0; v < n; ++v) {
                    dp[i][v][j % 2] = 0;
                    for (int k = 0; k < 4; ++k) {
                        int nx = i + dir[k][0];
                        int ny = v + dir[k][1];

                        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {

                            dp[i][v][j % 2] = (1LL * dp[i][v][j % 2] % MODN + 1LL * dp[nx][ny][(j-1) % 2] % MODN) % MODN;
                        }
                    }
                    total[i][v] = (1LL * total[i][v] % MODN + 1LL * dp[i][v][j % 2] % MODN) % MODN;
                }
            }
        }

        for (int v = 0; v < n; ++v) {
            ans = (1LL * ans % MODN + 1LL * total[0][v] % MODN + 1LL* total[m-1][v] % MODN) % MODN;
        }

        for (int i = 0; i < m; ++i) {
            ans = (1LL * ans % MODN + 1LL * total[i][0] % MODN + 1LL * total[i][n-1] % MODN) % MODN;
        }

        return ans;
    }
};
