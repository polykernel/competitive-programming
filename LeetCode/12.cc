/*
    Problem: 12. Integer to Roman
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char numerals[7] = {'I', 'V', 'X', 'L' ,'C', 'D', 'M'};
    string intToRoman(int num) {
        string res = "";
        int idx = 6;
        int basis = 1000;

        while (num > 0) {
            int u = num / basis;
            if (u == 9) {
                res.push_back(numerals[idx]);
                res.push_back(numerals[idx+2]);
            }
            else if (u == 4) {
                res.push_back(numerals[idx]);
                res.push_back(numerals[idx+1]);
            }
            else {
                if (u >= 5) {
                    res.push_back(numerals[idx+1]);
                    u -= 5;
                }
                if (u > 0) res.append(string(u, numerals[idx]));
            }

            idx -= 2;
            num %= basis;
            basis /= 10;
        }

        return res;
    }
};
