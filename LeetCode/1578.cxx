/*
    Problem: 1578. Minimum Time to Make Rope Colorful
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int curr = -1;
        int total = 0;
        int cmax = 0;
        int ans = 0;

        for (int i = 0; i < (int)colors.length(); ++i) {
            if (colors[i]-'a' != curr) {
                ans += total - cmax;
                curr = colors[i]-'a';
                total = neededTime[i];
                cmax = neededTime[i];
            }
            else {
                total += neededTime[i];
                cmax = max(cmax, neededTime[i]);
            }
        }

        ans += total - cmax;

        return ans;
    }
};
