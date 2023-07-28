/*
    Problem: 1232. Check If It Is a Straight Line
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        int dg = gcd(dx, dy);
        dx /= dg;
        dy /= dg;

        if (dx < 0 || (dx == 0 && dy < 0)) {
            dx = -dx;
            dy = -dy;
        }

        for (int i = 2; i < (int)coordinates.size(); ++i) {
            int cx = coordinates[i][0] - coordinates[i-1][0];
            int cy = coordinates[i][1] - coordinates[i-1][1];
            int cg = gcd(cx, cy);
            cx /= cg;
            cy /= cg;

            if (cx < 0 || (cx == 0 && cy < 0)) {
                cx = -cx;
                cy = -cy;
            }

            if (cx != dx || cy != dy) return false;
        }

        return true;
    }
};
