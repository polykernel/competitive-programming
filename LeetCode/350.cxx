/*
    Problem: 350. Intersection of Two Arrays II
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> freq;
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for (int i = 0; i < (int)nums2.size(); ++i) {
            ++freq[nums2[i]];
        }

        for (int i = 0; i < (int)nums1.size(); ++i) {
            if (freq[nums1[i]] > 0) {
                --freq[nums1[i]];
                res.push_back(nums1[i]);
            }
        }

        return res;
    }
};
