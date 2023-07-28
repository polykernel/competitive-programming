/*
    Problem: 485. Max Consecutive Ones
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int sum = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == 0) {
                ans = max(ans, sum);
                sum = 0;
            }
            else {
                ++sum;
            }
        }

        ans = max(ans, sum);

        return ans;
    }
};
