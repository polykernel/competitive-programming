/*
    Problem: 1239. Maximum Length of a Concatenated String with Unique Characters
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(int bm, int p, int l, vector<string>& arr) {
        if (p == (int)arr.size()) return l;

        int cm = 0;
        bool flag = true;
        for (char c : arr[p]) {
            if ((cm & (1 << (c - 'a'))) != 0) {
                flag = false;
                break;
            }
            cm |= 1 << (c - 'a');
        }

        int ans = f(bm, p+1, l, arr);
        if (flag && (bm & cm) == 0) ans = max(ans, f(bm ^ cm, p+1, l + (int)arr[p].length(), arr));

        return ans;
    }

    int maxLength(vector<string>& arr) {
        return f(0, 0, 0, arr);
    }
};
