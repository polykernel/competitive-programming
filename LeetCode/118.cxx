/*
    Problem: 118. Pascal's Triangle
    Difficulty: Easy 
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        for (int i = 0; i < numRows; ++i) {
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;

            for (int v = 1; v < i; ++v) {
                res[i][v] = res[i-1][v-1] + res[i-1][v];
            }
        }

        return res;
    }
};
