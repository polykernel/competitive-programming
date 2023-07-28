/*
    Problem: 435. Non-overlapping Intervals
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        int last_end = INT_MIN;

        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 0; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] >= last_end) {
                last_end = intervals[i][1];
            }
            else {
                ++count;
            }
        }

        return count;
    }
};
