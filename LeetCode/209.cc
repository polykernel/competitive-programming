/*
    Problem: 209. Minimum Size Subarray Sum
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ws = 0;
        int ans = INT_MAX;

        while (r < n) {
            ws += nums[r++];
            while (l < r && ws >= target) {
                ws -= nums[l++];
            }

            if (l > 0 && ws + nums[l-1] >= target) {
                ans = min(ans, r-l+1);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
