/*
    Problem: 392. Is Subsequence
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fm[26];

    bool isSubsequence(string s, string t) {
        int j = 0;
        int n = s.length();
        int m = t.length();

        for (int i = 0; i < m; ++i) {
            fm[t[i]-'a'].push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            int c = s[i]-'a';
            if (j >= m || fm[c].size() == 0 || j > fm[c].back()) return false;
            int p = lower_bound(fm[c].begin(), fm[c].end(), j) - fm[c].begin();
            j = fm[c][p] + 1;
        }

        return true;
    }
};
