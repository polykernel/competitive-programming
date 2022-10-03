/*
    Problem: 977. Squares of a Sorted Array
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MAXN = 10000;
    int freq[MAXN+1];
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int mx = 0;
        int mn = INT_MAX;
        int p = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            int x = abs(nums[i]);
            ++freq[x];
            if (x > mx) mx = x;
            if (x < mn) mn = x;
        }

        for (int i = mn; i <= mx; ++i) {
            if (freq[i] != 0) {
                for (int v = 0; v < freq[i]; ++v) {
                    res[p+v] = i * i;
                }
                p += freq[i];
            }
        }

        return res;
    }
};
