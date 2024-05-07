/*
    Problem: 2859. Sum of Values at Indices With K Set Bits
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        
        for (int i = 0; i < (int)nums.size(); i++) {
            int n = i;
            int c = 0;
            while (n) {
                n &= n - 1;
                c++;
            }
            if (c == k) {
                ans += nums[i];
            }
        }
        
        return ans;
    }
};
