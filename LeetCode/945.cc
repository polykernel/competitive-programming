/*
    Problem: 945. Minimum Deletions to Make Character Frequencies Unique
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size()-1; ++i) {
            if (nums[i] >= nums[i+1]) {
                ans += nums[i]+1 - nums[i+1];
                nums[i+1] = nums[i]+1;
            }
        }

        return ans;
    }
};
