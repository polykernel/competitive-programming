/*
    Problem: 69. Sqrt(x)
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int h = 46340;

        while (l < h) {
            int m = l+(h-l+1)/2;
            if (m*m <= x) {
                l = m;
            }
            else {
                h = m-1;
            }
        }

        return l;
    }
};
