/*
    Problem: 2244. Minimum Rounds to Complete All Tasks
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> freq;

    int minimumRounds(vector<int>& tasks) {
        int ans = 0;

        for (int i = 0; i < (int)tasks.size(); ++i) {
            ++freq[tasks[i]];
        }

        for (const auto& [k, v] : freq) {
            if (v == 1) return -1;
            else ans += (v + 2) / 3;
        }

        return ans;
    }
};
