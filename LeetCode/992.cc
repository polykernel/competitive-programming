/*
    Problem: 992. Subarrays with K Different Integers
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static constexpr int MAXN = 20000;
    int freq[MAXN+1];
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int count = 0;
        int ans = 0;
        int start = 0;

        /*
          idea: two pointer, for each subarray ending at r,
          find the first index l that make a[l..r] a subarray
          with k distinct integers, and find the last index l'
          such that a[l'..r] is still a subarray with k distinct
          integers, then all subarray starting in the range [l, l']
          and ending at r satisfy the condition.
        */
        for (int l = 0, r = 0; r < n; ++r) {
            ++freq[nums[r]];
            if (freq[nums[r]] == 1) ++count;
            if (count < k) continue;

            if (count > k) {
                while (l < r && count > k) {
                    if (freq[nums[l]] == 1) --count;
                    --freq[nums[l]];
                    ++l;
                }

                start = l;
            }
        
            while (l < r && count == k) {
                if (freq[nums[l]] == 1) break;
                --freq[nums[l]];
                ++l;
            }

            ans += l - start + 1;
        }

        return ans;
    }
};
