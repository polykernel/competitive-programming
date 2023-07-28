/*
    Problem: 2007. Find Original Array From Doubled Array
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<int, int, greater<int>> freq;
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> res;

        for (int i = 0; i < n; ++i) {
            ++freq[changed[i]];
        }

        for (auto& [k, v] : freq) {
            if (k == 0) {
                res.insert(res.end(), v / 2, 0);
                v %= 2;
            }
            else if (k % 2 == 0) {
                int j = min(freq[k/2], v);
                v -= j;
                freq[k/2] -= j;
                res.insert(res.end(), j, k / 2);
            }
        }

        return 2 * (int)res.size() == n ? res : vector<int>();
    }
};
