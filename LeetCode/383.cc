/*
    Problem: 383. Ransom Note
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int freq[26];
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < (int)magazine.size(); ++i) {
            ++freq[magazine[i]-'a'];
        }

        for (int i = 0; i < (int)ransomNote.size(); ++i) {
            if (freq[ransomNote[i]-'a'] == 0) return false;
            --freq[ransomNote[i]-'a'];
        }

        return true;
    }
};
