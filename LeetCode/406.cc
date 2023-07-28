/*
    Problem: 406. Queue Reconstruction by Height
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 2000;
    static const int MAXH = 1000000;
    bool vst[MAXN];
    int bit[MAXH+2];

    void update(int p, int v) {
        for (int i = p; i <= MAXH+1; i += (i & -i)) {
            bit[i] += v;
        }
    }

    int query(int p) {
        int res = 0;
        for (int i = p; i > 0; i -= (i & -i)) {
            res += bit[i];
        }
        return res;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        int n = people.size();

        for (int i = 0; i < n; ++i) {
            int min_p = -1;
            int min_v = -1;

            for (int v = 0; v < n; ++v) {
                if (vst[v]) continue;
                if (i - query(people[v][0]) == people[v][1] && (min_v == -1 || people[v][0] < min_p)) {
                    min_p = people[v][0];
                    min_v = v;
                }
            }

            vst[min_v] = true;
            update(min_p+1, 1);
            res.push_back(people[min_v]);
        }

        return res;
    }
};
