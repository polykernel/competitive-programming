/*
    Problem: 1295. Find Numbers with Even Number of Digits
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            int xs = 0;
            while (nums[i]) {
                nums[i] /= 10;
                ++xs;
            }

            if (xs % 2 == 0) ++ans;
        }

        return ans;
    }
};
