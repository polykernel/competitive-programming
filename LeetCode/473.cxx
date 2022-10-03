/*
    Problem: 473. Matchsticks to Square
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 15;
    int dp[1 << MAXN];
    int a[1 << MAXN];
    bool fmap[1 << MAXN];

    bool makesquare(vector<int>& matchsticks) {
        int total = 0;
        int n = matchsticks.size();
        vector<int> dv;
        for (int i = 0; i < n; ++i) {
            total += matchsticks[i];
            a[1 << i] = matchsticks[i];
        }

        if (total % 4 != 0) return false;

        int fs = (1 << n) - 1;

        for (int i = 1; i < fs; ++i) {
            dp[i] = a[i & (-i)] + dp[i - (i & (-i))];
            if (dp[i] == total /2) dv.push_back(i);
        }

        // kind of meet in the middle
        for (int i = 0; i < (int)dv.size(); ++i) { // split by half, 0s one half, 1s one half
            int mxb = dv[i] & (-dv[i]);
            for (int j = mxb; j < dv[i]; ++j) { // split by half, 0s one half, 1s one half
                if ((j & dv[i]) == j) {
                    if (dp[j] == total / 4) {
                        fmap[dv[i]] = true;
                    }
                }
            }

            int k = fs ^ dv[i];
            int mnb = k & (-k);
            for (int j = fs - 1; j > mnb; --j) {
                if ((j & k) == j) {
                    if (dp[j] == total / 4 && fmap[dv[i]]) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
