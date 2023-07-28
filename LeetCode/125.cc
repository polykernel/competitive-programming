/*
    Problem: 125. Valid Palindrome
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string t;

        for (int i = 0; i < (int)s.length(); ++i) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) t.push_back(s[i]);
            else if (s[i] >= 'A' && s[i] <= 'Z') t.push_back(s[i]-'A'+'a');
        }

        int n = t.length();

        for (int i = 0; i < n/2; ++i) {
            if (t[i] != t[n-1-i]) return false;
        }

        return true;
    }
};
