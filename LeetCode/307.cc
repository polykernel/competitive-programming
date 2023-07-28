/*
    Problem: 307. Range Sum Query - Mutable
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    vector<int> bit;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        bit.assign(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int k = i + (i & -i);
            bit[i] += nums[i-1];
            if (k <= n) {
                bit[k] += bit[i];
            }
        }
    }

    void update(int index, int val) {
        int diff = val - (query(index) - query(index-1));
        for (int i = ++index; i <= n; i += (i & -i)) {
            bit[i] += diff;
        }
    }

    int query(int index) {
        int res = 0;
        for (int i = ++index; i > 0; i -= (i & -i)) {
            res += bit[i];
        }
        return res;
    }

    int sumRange(int left, int right) {
        return query(right) - query(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
