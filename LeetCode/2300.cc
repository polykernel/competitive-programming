/*
    Problem: 2300. Successful Pairs of Spells and Potions
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = (int)spells.size();
        vector<int> ans(n, 0);

        sort(potions.begin(), potions.end());

        // TODO: rewrite as raw binary search to be faster
        for (int i = 0; i < n; ++i) {
            long long m = (success + spells[i] - 1) / spells[i];
            ans[i] = potions.end() - lower_bound(potions.begin(), potions.end(), m);
        }

        return ans;
    }
};
