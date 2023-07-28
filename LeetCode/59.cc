/*
    Problem: 59. Spiral Matrix II
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int cx = 0;
        int cy = 0;
        int k = 0;

        for (int i = 1; i <= n*n; ++i) {
            matrix[cx][cy] = i;
            int nx = cx + dir[k][1];
            int ny = cy + dir[k][0];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && matrix[nx][ny] == 0) {
                cx = nx;
                cy = ny;
            }
            else {
                k = (k+1) % 4;
                cx = cx + dir[k][1];
                cy = cy + dir[k][0];
            }
        }

        return matrix;
    }
};
