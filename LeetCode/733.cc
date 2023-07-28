/*
    Problem: 733. Flood Fill
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool vst[50][50];
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<int> q;
        vector<vector<int>> res(image);
        int m = (int)image.size();
        int n = (int)image[0].size();

        int startc = res[sr][sc];

        q.push(sr << 6 | sc);
        vst[sr][sc] = true;

        while (!q.empty()) {
            int cx = q.front() >> 6;
            int cy = q.front() & 63;
            q.pop();

            res[cx][cy] = color;

            for (int i = 0; i < 4; ++i) {
                int nx = cx + dir[i][0];
                int ny = cy + dir[i][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && res[nx][ny] == startc && !vst[nx][ny]) {
                    q.push(nx << 6 | ny);
                    vst[nx][ny] = true;
                }
            }
        }

        return res;
    }
};
