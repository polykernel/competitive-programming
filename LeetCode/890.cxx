/*
    Problem: 890. Find and Replace Pattern
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fmap[26];
    int rmap[26];

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;

        for (int i = 0; i < (int)words.size(); ++i) {
            memset(fmap, -1, sizeof(fmap));
            memset(rmap, -1, sizeof(rmap));

            bool flag = true;

            for (int v = 0; v < (int)pattern.length(); ++v) {
                int u = pattern[v] - 'a';
                int w = words[i][v] - 'a';
                if (fmap[u] == -1 && rmap[w] == -1) {
                    fmap[u] = w;
                    rmap[w] = u;
                }
                else if (rmap[w] != u) {
                    flag = false;
                    break;
                }
            }

            if (flag) res.push_back(words[i]);
        }

        return res;
    }
};
