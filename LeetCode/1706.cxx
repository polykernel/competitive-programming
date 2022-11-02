/*
    Problem: 1706. Where Will the Ball Fall
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; ++i) {
            int x = i;
            bool flag = true;
            for (int y = 0; y < m; ++y) {
                if (grid[y][x] == 1) {
                    if (x+1 >= n || grid[y][x+1] == -1) {
                        flag = false;
                        break;
                    }
                    else {
                        ++x;
                    }
                }
                else {
                    if (x-1 < 0 || grid[y][x-1] == 1) {
                        flag = false;
                        break;
                    }
                    else {
                        --x;
                    }
                }
            }

            if (flag) ans[i] = x;
        }

        return ans;
    }
};
