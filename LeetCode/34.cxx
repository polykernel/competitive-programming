/*
    Problem: 34. Find First and Last Position of Element in Sorted Array
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);

        if (nums.empty() || target > (int)nums[nums.size()-1]) return {-1, -1};

        int l = 0;
        int r = nums.size();

        while (l < r) {
            int m = l+(r-l)/2;
            if (nums[m] <= target) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        if (l-1 < 0 || nums[l-1] != target) return {-1, -1};
        res[1] = l-1;

        l = 0;
        r = nums.size();

        while (l < r) {
            int m = l+(r-l)/2;
            if (nums[m] >= target) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }

        res[0] = l;

        return res;
    }
};
