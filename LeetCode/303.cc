/*
    Problem: 303. Range Sum Query - Immutable
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    vector<int> psa;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        psa.resize(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            psa[i] = psa[i-1] + nums[i-1];
        }
    }

    int sumRange(int left, int right) {
        return psa[++right] - psa[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
