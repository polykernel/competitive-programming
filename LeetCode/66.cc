/*
    Problem: 66. Plus One
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.begin(), digits.end());

        ++res.back();

        for (int i = (int)res.size() - 1; i >= 1 && res[i] >= 10; --i) {
            res[i] %= 10;
            ++res[i-1];
        }

        if (res[0] >= 10) {
            res[0] %= 10;
            res.insert(res.begin(), 1);
        }

        return res;
    }
};
