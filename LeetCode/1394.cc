/*
    Problem: 1394. Find Lucky Integer in an Array
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 500;
    int freq[MAXN+1];

    int findLucky(vector<int>& arr) {
        int max_num = 0;
        int min_num = INT_MAX;

        for (int i = 0; i < (int)arr.size(); ++i) {
            ++freq[arr[i]];
            max_num = max(max_num, arr[i]);
            min_num = min(min_num, arr[i]);
        }

        for (int i = max_num; i >= min_num; --i) {
            if (freq[i] == i) return i;
        }

        return -1;
    }
};
