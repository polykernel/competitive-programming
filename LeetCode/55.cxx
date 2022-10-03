/*
    Problem: 55. Jump Game
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mi = 0;

        if (n == 1) return true;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (i < n-1 && mi <= i) return false;
            }
            else {
                mi = max(mi, i + nums[i]);
            }
        }

        return true;
    }
};
