/*
    Problem: 26. Remove Duplicates from Sorted Array
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 0;

        nums[counter++] = nums[0];
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            if (nums[i] < nums[i+1]) {
                nums[counter++] = nums[i+1];
            }
        }

        return counter;
    }
};
