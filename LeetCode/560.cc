/*
    Problem: 560. Subarray Sum Equals K
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> freq;
    int subarraySum(vector<int>& nums, int k) {
        freq[0] = 1;
        int ps = 0;
        int ans = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            ps += nums[i];
            ans += freq[ps-k];
            ++freq[ps];
        }

        return ans;
    }
};
