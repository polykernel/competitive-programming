/*
    Problem: 2831. Find the Longest Equal Subarray
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    constexpr static int MAXN = 100000;
    int freq[MAXN+1];
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int cnt = 0;

        // TODO: rewrite logic to be less ad-hoc
        freq[nums[0]] = 0;

        for (int l = 0, r = 0; l < n;) {
            cnt = r - l - freq[nums[l]];
            while (r < n && cnt < k) {
                freq[nums[r]]++;
                if (nums[r] != nums[l]) ++cnt;
                r++;
            }
            while (r < n && nums[r] == nums[l]) {
                freq[nums[r]]++;
                r++;
            }
            ans = std::max(ans, freq[nums[l]]);
            freq[nums[l]]--;
            l++;
        }
        
        return ans;
    }
};
