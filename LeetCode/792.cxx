/*
    Problem: 792. Number of Matching Subsequences
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fm[26];
    int numMatchingSubseq(string s, vector<string>& words) {
        int total = 0;
        int m = s.length();

        for (int i = 0; i < m; ++i) {
            fm[s[i]-'a'].push_back(i);
        }

        for (int i = 0; i < (int)words.size(); ++i) {
            int j = 0;
            bool flag = true;
            for (int v = 0; v < (int)words[i].length(); ++v) {
                int c = words[i][v] - 'a';
                if (j >= m || fm[c].size() == 0 || j > fm[c].back()) {
                    flag = false;
                    break;
                }
                int p = lower_bound(fm[c].begin(), fm[c].end(), j) - fm[c].begin();
                j = fm[c][p] + 1;
            }

            if (flag) ++total;
        }

        return total;
    }
};
