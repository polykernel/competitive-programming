/*
    Problem: 1047. Remove All Adjacent Duplicates In String 
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res;

        for (int i = 0; i < (int)s.length(); ++i) {
            if (!res.empty() && s[i] == res.back()) {
                res.pop_back();
            }
            else {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};
