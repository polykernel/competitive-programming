/*
    Problem: 3. Longest Substring Without Repeating Characters 
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int freq[256];
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        int r = 0;
        int ans = 0;

        while (l <= r && r < n) {
            while (freq[s[r]] == 0 && r < n) {
                ++freq[s[r]];
                ++r;
            }
            ans = max(ans, r-l);
            --freq[s[l]];
            ++l;
        }

        return ans;
    }
};
