/*
    Problem: 239. Sliding Window Maximum
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        deque<pair<int, int>> dq;

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                res[i-k] = dq.front().first;
                if (dq.front().second == i-k) dq.pop_front();
            }
            while (!dq.empty() && dq.back().first <= nums[i]) dq.pop_back();
            dq.push_back({nums[i], i});
        }

        res[n-k] = dq.front().first;

        return res;
    }
};
