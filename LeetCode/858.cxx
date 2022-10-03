/*
    Problem: 858. Mirror Reflection
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        bool ps = 0;
        int ypos = 0;

        do {
            ps ^= 1;
            ypos += q;
        } while ((ypos % p) != 0);

        if (!ps) {
            return 2;
        }
        else {
            if ((ypos / p) % 2 == 0) return 0;
            else return 1;
        }
    }
};
