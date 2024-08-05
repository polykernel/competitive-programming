/*
    Problem: 3242. Design Neighbor Sum Service
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;
class neighborSum {
private:
    static constexpr int MAXN = 100;
    int adjSum[MAXN];
    int diagSum[MAXN];
public:
    neighborSum(vector<vector<int>>& grid) {
        int n = grid.size();
        pair<int, int> dirs[8] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int k = 0;
                adjSum[grid[i][j]] = 0;
                diagSum[grid[i][j]] = 0;
                while (k < 4) {
                    auto [incx, incy] = dirs[k];
                    int ni = i + incx;
                    int nj = j + incy;
                    if (0 <= ni && ni < n && 0 <= nj && nj < n) {
                        adjSum[grid[i][j]] += grid[ni][nj];
                    }
                    k++;
                }
                while (k < 8) {
                    auto [incx, incy] = dirs[k];
                    int ni = i + incx;
                    int nj = j + incy;
                    if (0 <= ni && ni < n && 0 <= nj && nj < n) {
                        diagSum[grid[i][j]] += grid[ni][nj];
                    }
                    k++;
                }
            }
        }
    }

    int adjacentSum(int value) {
        return adjSum[value];
    }

    int diagonalSum(int value) {
        return diagSum[value];
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
