/*
    Problem: 2139. Minimum Moves to Reach Target Score
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;

        while (target > 1) {
            if (maxDoubles == 0) {
                count += target - 1;
                target = 1;
            }
            else {
                if (target % 2 == 0 && maxDoubles > 0) {
                    target /= 2;
                    --maxDoubles;
                }
                else {
                    --target;
                }

                ++count;
            }
        }

        return count;
    }
};
