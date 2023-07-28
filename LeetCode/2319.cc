/*
    Problem: 2319. Check if Matrix Is X-Matrix
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; ++i) {
            for (int v = 0; v < n; ++v) {
                if (v == i || v == n-1-i) {
                    if (grid[i][v] == 0) {
                        return false;
                    }
                }
                else {
                    if (grid[i][v] != 0) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
