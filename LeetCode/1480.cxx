/*
    Problem: 1480. Running Sum of 1d Array
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.begin(), nums.end());

        for (int i = 1; i < (int)res.size(); ++i) {
            res[i] += res[i-1];
        }

        return res;
    }
};
