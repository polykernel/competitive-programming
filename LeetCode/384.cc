/*
    Problem: 384. Shuffle an Array
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& nums) {
        arr = nums;
    }

    vector<int> reset() {
        return arr;
    }

    vector<int> shuffle() {
        vector<int> res(arr);
        int rseed = chrono::system_clock::now().time_since_epoch().count();
        mt19937 engine(rseed);

        for (int i = (int)res.size()-1; i >= 0; --i) {
            uniform_int_distribution<int> gen(0, i);
            int j = gen(engine);
            int tmp = res[i];
            res[i] = res[j];
            res[j] = tmp;
        }

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
