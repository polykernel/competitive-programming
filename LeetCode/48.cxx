/*
    Problem: Rotate Image
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int corner[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n/2; ++i) {
            int len = n-2*i-1;

            for (int j = 0; j < len; ++j) {
                int temp = matrix[i+len*corner[3][1]+j*dir[3][1]][i+len*corner[3][0]+j*dir[3][0]];
                for (int k = 3; k >= 1; --k) {
                    int nx = i + len*corner[k][1] + j*dir[k][1];
                    int ny = i + len*corner[k][0] + j*dir[k][0];
                    int ox = i + len*corner[k-1][1] + j*dir[k-1][1];
                    int oy = i + len*corner[k-1][0] + j*dir[k-1][0];
                    matrix[nx][ny] = matrix[ox][oy]; 
                }
                matrix[i+len*corner[0][1]+j*dir[0][1]][i+len*corner[0][0]+j*dir[0][0]] = temp;
            }
        }
    }
};
