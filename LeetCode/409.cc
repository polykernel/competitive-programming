/*
    Problem: 409. Longest Palindrome
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int freq[52];
    int longestPalindrome(string s) {
        for (int i = 0; i < (int)s.length(); ++i) {
            // compress 'A'-'Z' into the range 26-51 so we can store
            // the frequency consecutively
            if (s[i] < 'a') ++freq[s[i]-'A'+26];
            else ++freq[s[i]-'a'];
        }

        bool dl = false;
        int ans = 0;
        for (int i = 0; i < 52; ++i) {
            if (!dl && freq[i] % 2 != 0) dl = true;
            ans += freq[i] / 2;
        }

        ans *= 2;

        return dl ? ans + 1 : ans;
    }
};
