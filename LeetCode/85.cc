/*
    Problem: 85. Maximal Rectangle
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 200;
    int col[MAXN+1][MAXN+1];
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ma = 0;

        for (int i = 1; i <= m; ++i) {
            for (int v = 1; v <= n; ++v) {
                col[v][i] = col[v][i-1];
                if (matrix[i-1][v-1] == '1') ++col[v][i];
            }
        }

        for (int r1 = 1; r1 <= m; ++r1) {
            for (int r2 = 1; r2 <= m; ++r2) {
                int h = r2-r1+1;
                int c1, c2;
                for (c1 = 1, c2 = 1; c2 <= n; ++c2) {
                    if (col[c2][r2] - col[c2][r1-1] < h) {
                        ma = max(ma, (c2-c1) * (r2-r1+1));
                        c1 = c2+1;
                    }
                }
                ma = max(ma, (c2-c1) * (r2-r1+1));
            }
        }

        return ma;
    }
};
