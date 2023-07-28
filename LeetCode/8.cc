/*
    Problem: 8. String to Integer (atoi)
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int ans = 0;
        int n = s.length();
        int sign = 1;

        while (i < n && s[i] == ' ') ++i;

        if (i < n) {
            if (s[i] == '-') {
                sign = -1;
                ++i;
            }
            else if (s[i] == '+') {
                ++i;
            }

            int digit_count = 0;

            while (i < n && s[i] >= '0' && s[i] <= '9') {
                if (digit_count < 9) {
                    int tmp = ans;
                    ans = ans * 10 + sign * (s[i] - '0');
                    if (ans != tmp) ++digit_count;
                }
                else if (digit_count == 9) {
                    int m = sign == 1 ? INT_MAX : INT_MIN;
                    int k = 100000000;
                    int x = ans;
                    int flag = -1;

                    while (k > 1) {
                        if (flag == -1 && abs(x / k) > abs(m / (k * 10))) {
                            if (sign == 1) ans = INT_MAX;
                            else ans = INT_MIN;
                            flag = 0;
                            break;
                        }
                        else {
                            if (abs(x / k) < abs(m / (k * 10))) flag = 1;
                        }

                        x %= k;
                        m %= (k * 10);
                        k /= 10;
                    }

                    if (flag == -1) {
                        if (abs(m % 10) < s[i]-'0') {
                            if (sign == 1) ans = INT_MAX;
                            else ans = INT_MIN;
                        }
                        else {
                            ans = ans * 10 + sign * (s[i]-'0');
                            ++digit_count;
                        }
                    }
                    else if (flag == 1) {
                        ans = ans * 10 + sign * (s[i]-'0');
                        ++digit_count;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (sign == 1) ans = INT_MAX;
                    else ans = INT_MIN;
                    break;
                }
                ++i;
            }
        }

        return ans;
    }
};
