/*
    Problem: 532. K-diff Pairs in an Array
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXA = 10000000;
    int freq[2*MAXA+1];
    int findPairs(vector<int>& nums, int k) {
        vector<int> fv;
        int ans = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (++freq[nums[i]+MAXA] == 1) fv.push_back(nums[i]);
        }

        for (int i = 0; i < (int)fv.size(); ++i) {
            if (fv[i]-k >= -MAXA) {
                --freq[fv[i]+MAXA];
                ans += freq[fv[i]-k+MAXA] > 0;
                ++freq[fv[i]+MAXA];
            }
        }

        return ans;
    }
};
