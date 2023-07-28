/*
    Problem: 41. First Missing Positive
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<int> vst;
    int firstMissingPositive(vector<int>& nums) {
        int ans = INT_MAX;

        vst.insert(0);

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] > 0 && vst.find(nums[i]) == vst.end()) vst.insert(nums[i]);
        }

        for (auto it = vst.cbegin(); it != vst.cend(); ++it) {
            if (*it < INT_MAX && vst.find(*it+1) == vst.end()) ans = min(ans, *it+1);
        }

        return ans;
    }
};
