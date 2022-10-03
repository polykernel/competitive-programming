/*
    Problem: 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MODN = 1000000007;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int max_x = horizontalCuts.front();
        for (int i = 1; i < (int)horizontalCuts.size(); ++i) {
            max_x = max(max_x, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        max_x = max(max_x, h - horizontalCuts.back());

        int max_y = verticalCuts.front();
        for (int i = 1; i < (int)verticalCuts.size(); ++i) {
            max_y = max(max_y, verticalCuts[i] - verticalCuts[i-1]);
        }
        max_y = max(max_y, w - verticalCuts.back());

        return (1LL * max_x * max_y) % MODN;
    }
};
