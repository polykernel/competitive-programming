/*
    Problem: 567. Permutation in String
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int freq1[26];
    int freq2[26];
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int match = 0;

        if (n > m) return false;

        for (int i = 0; i < n; ++i) {
            ++freq1[s1[i]-'a'];
            ++freq2[s2[i]-'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (freq1[i] == freq2[i]) ++match;
        }

        if (match == 26) return true;

        for (int i = 0; i < m-n; ++i) {
            --freq2[s2[i]-'a'];
            if (freq2[s2[i]-'a'] == freq1[s2[i]-'a']) ++match;
            else if (freq2[s2[i]-'a'] == freq1[s2[i]-'a'] - 1) --match;

            ++freq2[s2[i+n]-'a'];
            if (freq2[s2[i+n]-'a'] == freq1[s2[i+n]-'a']) ++match;
            else if (freq2[s2[i+n]-'a'] == freq1[s2[i+n]-'a'] + 1) --match;

            if (match == 26) return true;
        }

        return false;
    }
};
