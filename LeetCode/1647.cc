/*
    Problem: 1647. Minimum Deletions to Make Character Frequencies Unique
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 100000;
    int ds[MAXN+1];
    int freq[26];

    int find(int x) {
        if (ds[x] != x) ds[x] = find(ds[x]);
        return ds[x];
    }

    int minDeletions(string s) {
        int ans = 0;

        for (int i = 0; i < (int)s.length(); ++i) {
            ds[i+1] = i+1;
            ++freq[s[i]-'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (freq[i] != 0) {
                int fr = find(freq[i]);
                ans += freq[i] - fr;
                if (fr > 0) ds[fr] = find(fr-1);
            }
        }

        return ans;
    }
};
