/*
    Problem: 1662. Check If Two String Arrays are Equivalent
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int lp = 0;
        int rp = 0;
        int i = 0;
        int j = 0;

        bool flag = true;

        while (i < (int)word1.size() && j < (int)word2.size()) {
            while (lp < (int)word1[i].length() && rp < (int)word2[j].length()) {
                if (word1[i][lp] != word2[j][rp]) {
                    flag = false;
                    break;
                }
                ++lp;
                ++rp;
            }

            if (!flag) break;

            if (lp == (int)word1[i].length()) {
                lp = 0;
                ++i;
            }

            if (rp == (int)word2[j].length()) {
                rp = 0;
                ++j;
            }
        }

        return flag && (i == (int)word1.size() && j == (int)word2.size());
    }
};
