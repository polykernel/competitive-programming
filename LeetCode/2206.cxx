/*
    Problem: 2206. Divide Array Into Equal Pairs
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static constexpr int MAXN = 500;
    int freq[MAXN+1];
    bool divideArray(vector<int>& nums) {
        int mn = MAXN+1;
        int mx = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            ++freq[nums[i]];
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        for (int i = mn; i <= mx; ++i) {
            if (freq[i] % 2 != 0) return false;
        }

        return true;
    }
};
