/*
    Problem: 128. Longest Consecutive Sequence
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> ds;
    unordered_map<int, int> sz;

    int find(int x) {
        if (ds.count(x) == 1) return ds[x] = find(ds[x]);
        else return x;
    }

    int longestConsecutive(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (ds.count(nums[i]) == 1) continue;

            int ur = find(nums[i]);
            if (sz.count(ur) == 0) sz[ur] = 1;

            int vr = find(nums[i]-1);
            if (sz.count(vr) == 0) sz[vr] = 1;

            ds[ur] = vr;
            sz[vr] += sz[ur];

            ans = max(ans, sz[vr] - 1);
        }

        return ans;
    }
};
