/*
    Problem: 344. Reverse String
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        for (int i = 0; i < n/2; ++i) {
            char tmp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = tmp;
        }
    }
};
