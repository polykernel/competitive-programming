/*
    Problem: 2131. Longest Palindrome by Concatenating Two Letter Words
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int freq[26][26];
    int longestPalindrome(vector<string>& words) {
        vector<int> cl;
        for (int i = 0; i < (int)words.size(); ++i) {
            int u = words[i][0] - 'a';
            int v = words[i][1] - 'a';
            if (freq[u][v] == 0 && freq[v][u] == 0) {
                cl.push_back(i);
            }
            ++freq[u][v];
        }

        bool dl = false;
        int ans = 0;
        for (int j = 0; j < (int)cl.size(); ++j) {
            int u = words[cl[j]][0] - 'a';
            int v = words[cl[j]][1] - 'a';
            if (u == v) {
                if (freq[u][v] % 2 != 0) dl = true;
                ans += freq[u][v] / 2;
            }
            else {
                ans += min(freq[u][v], freq[v][u]);
            }
        }

        ans *= 4;

        return dl ? ans + 2 : ans;
    }
};
