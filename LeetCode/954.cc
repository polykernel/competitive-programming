/*
    Problem: 954. Array of Doubled Pairs
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<int, int, greater<int>> freq;
    bool canReorderDoubled(vector<int>& arr) {
        int count = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            ++freq[arr[i]];
        }

        for (auto& [k, v] : freq) {
            if (k == 0) {
                count += v / 2;
                v %= 2;
            }
            else if (k % 2 == 0) {
                int j = min(freq[k/2], v);
                v -= j;
                freq[k/2] -= j;
                count += j;
            }
        }

        return count == n / 2;
    }
};
