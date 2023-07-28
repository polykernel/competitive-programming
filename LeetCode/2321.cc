/*
    Problem: 2321. Maximum Score Of Spliced Array
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum1 = 0;
        int sum2 = 0;
        int diff1 = 0;
        int diff2 = 0;
        int best1 = 0;
        int best2 = 0;

        for (int i = 0; i < n; ++i) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            diff1 = max(0, diff1 + nums2[i] - nums1[i]);
            best1 = max(best1, diff1);
            diff2 = max(0, diff2 + nums1[i] - nums2[i]);
            best2 = max(best2, diff2);
        }

        return max(sum1 + best1, sum2 + best2);
    }
};
