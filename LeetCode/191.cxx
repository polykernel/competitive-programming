/*
    Problem: 191. Number of 1 Bits
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();

        for (int i = 0; i < (int)nums.size(); ++i) {
            ans ^= (i ^ nums[i]);
        }

        return ans;
    }
};
