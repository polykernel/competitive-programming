/*
    Problem: 345. Reverse Vowels of a String
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char, bool> cmap = {
        {'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true},
        {'A', true}, {'E', true}, {'I', true}, {'O', true}, {'U', true}
    };
    string reverseVowels(string s) {
        int l = 0;
        int r = (int)s.length() - 1;

        for (int l = 0, r = (int)s.length()-1; l < r; ++l, --r) {
            while (l < (int)s.length() && !cmap[s[l]]) ++l;
            while (r >= 0 && !cmap[s[r]]) --r;

            if (l < r) {
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
            }
        }

        return s;
    }
};
