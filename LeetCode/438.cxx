/*
    Problem: 438. Find All Anagrams in a String
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int freq1[26];
    int freq2[26];
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.size();
        int m = p.size();
        int match = 0;

        if (n < m) return res;

        for (int i = 0; i < m; ++i) {
            ++freq1[p[i]-'a'];
            ++freq2[s[i]-'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (freq1[i] == freq2[i]) ++match;
        }

        if (match == 26) res.push_back(0);

        for (int i = 0; i < n-m; ++i) {
            --freq2[s[i]-'a'];
            if (freq2[s[i]-'a'] == freq1[s[i]-'a']) ++match;
            else if (freq2[s[i]-'a'] == freq1[s[i]-'a'] - 1) --match;

            ++freq2[s[i+m]-'a'];
            if (freq2[s[i+m]-'a'] == freq1[s[i+m]-'a']) ++match;
            else if (freq2[s[i+m]-'a'] == freq1[s[i+m]-'a'] + 1) --match;

            if (match == 26) res.push_back(i+1);
        }

        return res;
    }
};
