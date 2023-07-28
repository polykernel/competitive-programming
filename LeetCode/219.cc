/*
    Problem: 219. Contains Duplicate II
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> last_index;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (last_index.count(nums[i]) > 0 && i - last_index[nums[i]] <= k) return true;
            last_index[nums[i]] = i;
        }

        return false;
    }
};
