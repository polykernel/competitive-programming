/*
    Problem: 387. First Unique Character in a String
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int freq[26];
    int firstUniqChar(string s) {
        for (int i = 0; i < (int)s.length(); ++i) {
            ++freq[s[i]-'a'];
        }

        for (int i = 0; i < (int)s.length(); ++i) {
            if (freq[s[i]-'a'] == 1) return i;
        }

        return -1;
    }
};
