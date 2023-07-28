/*
    Problem: 242. Valid Anagram
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int freq[26];
    bool isAnagram(string s, string t) {
        int unique_count = 0;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (freq[s[i]-'a']++ == 0) ++unique_count;
        }

        for (int i = 0; i < (int)t.length(); ++i) {
            if (freq[t[i]-'a'] == 0) return false;
            if (--freq[t[i]-'a'] == 0) --unique_count;
        }

        return unique_count == 0;
    }
};
