/*
    Problem: 14. Longest Common Prefix
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int min_len = INT_MAX;

        for (int i = 0; i < (int)strs.size(); ++i) {
            if ((int)strs[i].length() < min_len) {
                min_len = strs[i].length();
            }
        }

        for (int i = 0; i < min_len; ++i) {
            for (int v = 0; v < (int)strs.size(); ++v) {
                if (strs[v][i] != strs[0][i]) {
                    return res;
                }
            }
            res.push_back(strs[0][i]);
        }

        return res;
    }
};

int main() {
    return 0;
}
