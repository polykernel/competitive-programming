/*
    Problem: 462. Minimum Moves to Equal Array Elements II
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MIN_NUM = -1000000000;
    const int MAX_NUM = 1000000000;

    long long check(vector<int>& nums, int x) {
        long long ans = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            ans += abs(nums[i] - x);
        }

        return ans;
    }

    int minMoves2(vector<int>& nums) {
        int l = INT_MAX;
        int r = INT_MIN;

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] < l) l = nums[i];
            if (nums[i] > r) r = nums[i];
        }

        while (l < r) {
            int m = l+(r-l)/2;

            if (check(nums, m) < check(nums, m+1)) r = m;
            else l = m + 1;
        }

        return check(nums, l);
    }
};
