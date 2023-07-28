/*
    Problem: 2006. Count Number of Pairs With Absolute Difference K
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXA = 100;
    int freq[MAXA+1];

    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i]-k >= 1) ans += freq[nums[i]-k];
            if (nums[i]+k <= MAXA) ans += freq[nums[i]+k];
            ++freq[nums[i]];
        }

        return ans;
    }
};
