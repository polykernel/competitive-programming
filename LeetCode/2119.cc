/*
    Problem: 2119. A Number After a Double Reversal
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num == 0) return true;
        else if (num % 10 == 0) return false;
        else return true;
    }
};
