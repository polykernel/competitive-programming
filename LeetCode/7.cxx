/*
    Problem: 7. Reverse Integer
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        int digit_count = 1;
        int i;
        for (i = 10; i < 1000000000 && x / i; i *= 10) {
            ++digit_count;
        }
        if (x / i) ++digit_count;

        if (digit_count <= 9) {
            while (x != 0) {
                ans = ans * 10 + x % 10;
                x /= 10;
            }
        }
        else {
            bool flag = false;
            int m = x > 0 ? INT_MAX : INT_MIN;
            int k = 1000000000;
            while (x != 0) {
                if (!flag && abs(x % 10) > abs(m / k)) {
                    ans = 0;
                    break;
                }
                else {
                    if (abs(x % 10) < abs(m / k)) flag = true;
                    ans = ans * 10 + x % 10;
                }
                x /= 10;
                m %= k;
                k /= 10;
            }
        }

        return ans;
    }
};
