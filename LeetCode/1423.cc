/*
    Problem: 1423. Maximum Points You Can Obtain from Cards
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int current_sum = 0;
        int n = cardPoints.size();

        for (int i = 0; i < k; ++i) {
            current_sum += cardPoints[i];
        }

        int mx = current_sum;

        for (int i = 0; i < k; ++i) {
            current_sum += cardPoints[n-1-i] - cardPoints[k-1-i];
            if (current_sum > mx) mx = current_sum;
        }

        return mx;
    }
};
