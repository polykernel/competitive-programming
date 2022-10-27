/*
    Problem: 835. Image Overlap
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static constexpr int MAXN = 30;
    int row1[2][MAXN];
    int row2[2][MAXN];
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = (int)img1.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int v = 0; v < n; ++v) {
                if (img1[i][v] == 1) {
                    row1[0][i] |= 1 << (n-1-v);
                    row1[1][i] |= 1 << v;
                }
                if (img2[i][v] == 1) {
                    row2[0][i] |= 1 << (n-1-v);
                    row2[1][i] |= 1 << v;
                }
            }
        }

        // idea; consider only the case when we shift down and right. To simulate shifting right by v rows
        // we do right shift of v on the row bitmasks. To simulate shifting down by i rows, we align the
        // the j-th row in the second matrix with the j-ith row in the first matrix(since all rows above the j-th
        // row in the second matrix is matched with a zero row in the first matrix after the shift).
        // we can also shift down and left by inverting the row bitmasks. By symmetry, the first matrix shifted
        // up is equivalent to the second matrix shifted down, so we invert the comparison of rows(swapping the matrix)
        // by aligning the j-th row in the first matrix with the j-1th row in the second matrix.
        // Time complexity: O(4 * n^3 * logn) = O(n^3 * logn)

        for (int v = 0; v < n; ++v) {
            for (int i = 0; i < n; ++i) {
                int cnt1 = 0;
                int cnt2 = 0;
                int cnt3 = 0;
                int cnt4 = 0;
                for (int j = i; j < n; ++j) {
                    // shift down and right
                    for (int k = (row1[0][j-i] >> v) & row2[0][j]; k > 0; k &= (k-1)) ++cnt1;
                    // shift down and left
                    for (int l = (row1[1][j-i] >> v) & row2[1][j]; l > 0; l &= (l-1)) ++cnt2;
                    // shift up and right
                    for (int p = (row2[0][j-i] >> v) & row1[0][j]; p > 0; p &= (p-1)) ++cnt3;
                    // shift up and left
                    for (int q = (row2[1][j-i] >> v) & row1[1][j]; q > 0; q &= (q-1)) ++cnt4;
                }
                // take the maximum of all shifts by (i, v)
                ans = max({ans, cnt1, cnt2, cnt3, cnt4});
            }
        }

        return ans;
    }
};
