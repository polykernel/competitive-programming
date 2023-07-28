/*
    Problem: 74. Search a 2D Matrix
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int h = matrix.size();
        int n = matrix[0].size();

        if (target > matrix[h-1][n-1]) return false;

        while (l < h) {
            int m = l+(h-l)/2;

            if (matrix[m][n-1] >= target) {
                h = m;
            }
            else {
                l = m + 1;
            }
        }

        int j = 0;
        int k = n;

        while (j < k) {
            int m = j+(k-j)/2;

            if (matrix[l][m] >= target) {
                k = m;
            }
            else {
                j = m + 1;
            }
        }

        if (matrix[l][j] == target) return true;
        else return false;
    }
};
