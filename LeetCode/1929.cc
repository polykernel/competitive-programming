/*
    Problem: 1929. Concatenation of Array
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size());

        for (int i = 0; i < (int)ans.size(); ++i) {
            ans[i] = nums[i % (int)nums.size()];
        }

        return ans;
    }
};
