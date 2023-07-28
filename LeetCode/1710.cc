/*
    Problem: 1710. Maximum Units on a Truck
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int count = 0;

        for (int i = 0; i < (int)boxTypes.size() && truckSize > 0; ++i) {
            if (boxTypes[i][0] > truckSize) {
                count += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
            else {
                count += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
        }

        return count;
    }
};
