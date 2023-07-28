/*
    Problem: 523. Continuous Subarray Sum
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> rindex;
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool flag = false;
        int ps = 0;

        rindex[0] = 0;

        for (int i = 1; i <= (int)nums.size(); ++i) {
            ps = (ps + nums[i-1]) % k;
            if (rindex.count(ps % k) > 0) {
                if (rindex[ps % k] < i-1) {
                    flag = true;
                    break;
                }
            }
            else {
                rindex[ps % k] = i;
            }
        }

        return flag;
    }
};
