/*
    Problem: 1074. Number of Submatrices That Sum to Target
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 100;
    unordered_map<int, int> freq;
    int psa[MAXN+1][MAXN+1];
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 1; i <= m; ++i) {
            for (int v = 1; v <= n; ++v) {
                psa[i][v] = psa[i-1][v] + psa[i][v-1] - psa[i-1][v-1] + matrix[i-1][v-1];
            }
        }

        for (int r1 = 1; r1 <= m; ++r1) {
            for (int r2 = r1; r2 <= m; ++r2) {
                freq.clear();
                freq[0] = 1;
                for (int c = 1; c <= n; ++c) {
                    int sum = psa[r2][c] - psa[r1-1][c];
                    count += freq[sum - target];
                    ++freq[sum];
                }
            }
        }

        return count;
    }
};
