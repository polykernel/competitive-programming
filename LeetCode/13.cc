/*
    Problem: 13. Roman to Integer
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char, int> kmap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    unordered_map<int, char> vmap = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            bool flag = false;
            for (int v = 1; v <= 100; v *= 10) {
                if (s[i] == vmap[v] && i+1 < n && (s[i+1] == vmap[5 * v] || s[i+1] == vmap[10 * v])) {
                    ans += kmap[s[i+1]] - kmap[s[i]];
                    ++i;
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                ans += kmap[s[i]];
            }
        }

        return ans;
    }
};
