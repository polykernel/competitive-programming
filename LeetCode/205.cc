/*
    Problem: 205. Isomorphic Strings
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char, char> fmap;
    unordered_map<char, char> rmap;
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < (int)s.length(); ++i) {
            int u = s[i];
            int v = t[i];
            if (fmap.count(u) == 0 && rmap.count(v) == 0) {
                fmap[u] = v;
                rmap[v] = u;
            }
            else if (fmap[u] != v) {
                return false;
            }
        }

        return true;
    }
};
