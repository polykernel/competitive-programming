/*
    Problem: 434. Number of Segments in a String
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        int n = (int)s.length();

        if (n == 0) return 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == ' ' && s[i-1] != ' ') ++cnt;
        }

        if (s[n-1] != ' ') ++cnt;

        return cnt;
    }
};
