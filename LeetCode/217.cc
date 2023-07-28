/*
    Problem: 217. Contain Duplicate
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (++freq[nums[i]] > 1) return true;
        }

        return false;
    }
};
