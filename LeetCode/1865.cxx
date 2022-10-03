/*
    Problem: 1865. Finding Pairs With a Certain Sum
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class FindSumPairs {
public:
    unordered_map<int, int> freq2;
    unordered_map<int, int> freq1;
    vector<int> backup;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < (int)nums1.size(); ++i) {
            ++freq1[nums1[i]];
        }
        for (int i = 0; i < (int)nums2.size(); ++i) {
            ++freq2[nums2[i]];
        }
        backup = nums2;
    }

    void add(int index, int val) {
        --freq2[backup[index]];
        ++freq2[backup[index]+val];
        backup[index] += val;
    }

    int count(int tot) {
        int ans = 0;
        for (const auto& [k, v] : freq1) {
            if (freq2.count(tot - k) != 0) ans += freq2[tot - k] * v;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
