/*
    Problem: 283. Move Zeroes
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first_zero = 0;

        while (first_zero < nums.size() && nums[first_zero] != 0) ++first_zero;

        for (int i = first_zero+1; i < (int)nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[first_zero] = nums[i];
                nums[i] = 0;
                ++first_zero;
            }
        }
    }
};
