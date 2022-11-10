/*
    Problem: 704. Binary Search
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = (int)nums.size()-1;

        while (l <= h) {
            int m = l+(h-l)/2;

            if (nums[m] == target) return m;
            else if (nums[m] > target) h = m - 1;
            else l = m + 1;
        }

        return -1;
    }
};
