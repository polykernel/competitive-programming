/*
    Problem: 547. Number of Provinces
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 200;
    int ds[MAXN+1];

    int find(int x) {
        if (ds[x] != x) ds[x] = find(ds[x]);
        return ds[x];
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = n;

        for (int i = 1; i <= n; ++i) {
            ds[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) {
                    int ur = find(i+1);
                    int vr = find(j+1);

                    if (ur != vr) {
                        ds[ur] = vr;
                        --ans;
                    }
                }
            }
        }

        return ans;
    }
};
