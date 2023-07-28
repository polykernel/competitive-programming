/*
    Problem: 77. Combinations
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> log_2;
    void choose(int mask, int rmask, int smask, int n, int k, vector<vector<int>>& comb) {
        if (k == 0) {
            vector<int> res;

            for (int p = ~mask & smask; p > 0; p = p & (p-1)) {
                res.push_back(log_2[p & -p]);
            }

            comb.push_back(res);
        }
        else {
            // smask is the range of bits that represent 1..n, i.e 0..111110
            // we want to efficiently query the most significant bit in ~mask & smask
            // so we store the ~mask in reverse order in rmask, then the most significant
            // bit is the least significant bit of rmask.
            // the subset we consider is strictly all bits higher than the most significant
            // bit, so it is (mask & ((1 << (MSB+1) - 1)) & smask.
            int rlsb = rmask & -rmask;
            int rlm = ~((1 << (n+1 - log_2[rlsb] + 1)) - 1) & smask;
            for (int i = mask & rlm; i > 0; i = i & (i-1)) {
                int lb = i & -i;
                int lm = ~lb & smask;
                int rb = 1 << (n+1 - log_2[lb]);
                // if lowest bit lb in mask is chosen, then set the corresponding bit
                // in rmask
                choose(mask & lm, rmask | rb, smask, n, k-1, comb);
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        for (int i = 0; i <= n+1; ++i) {
            log_2[1 << i] = i;
        }

        vector<vector<int>> res;

        choose((1 << (n+1)) - 2, 1 << (n+1), (1 << (n+1)) - 2, n, k, res);

        return res;
    }
};
