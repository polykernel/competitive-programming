/*
    Problem: 315. Count of Smaller Number After Self
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 10000;
    int bit[2*MAXN+2];

    void update(int p, int v) {
        for (int i = p+MAXN+1; i <= 2*MAXN+1; i += (i & -i)) {
            bit[i] += v;
        }
    }

    int query(int p) {
        int res = 0;
        for (int i = p+MAXN+1; i > 0; i -= (i & -i)) {
            res += bit[i];
        }
        return res;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size());

        for (int i = (int)nums.size()-1; i >= 0; --i) {
            counts[i] = query(nums[i]-1);
            update(nums[i], 1);
        }

        return counts;
    }
};
