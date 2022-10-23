/*
    Problem: 646. Maximum Length of Pair Chain
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);

        int cnt = 0;
        int lr = -1001;

        for (int i = 0; i < (int)pairs.size(); ++i) {
            if (pairs[i][0] > lr) {
                ++cnt;
                lr = pairs[i][1];
            }
        }

        return cnt;
    }
};
