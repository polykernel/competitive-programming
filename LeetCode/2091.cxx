/*
    Problem: 2091.Removing Minimum and Maximum From Array
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = 0;
        int mx = 0;
        int n = nums.size();

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[mx]) mx = i;
            if (nums[i] < nums[mn]) mn = i;
        }

        if (mx < mn) swap(mx, mn);

        return min({mx + 1, n - mn, n - mx + mn + 1});
    }
};
