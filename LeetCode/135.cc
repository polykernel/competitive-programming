/*
    Problem: 135. Candy
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 20000;
    int amount[MAXN];

    int candy(vector<int>& ratings) {
        int ans = 1;
        amount[0] = 1;

        for (int i = 1; i < (int)ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                amount[i] = amount[i-1] + 1;
            }
            else {
                amount[i] = 1;
                if (amount[i-1] == 1) {
                    int j = i-1;
                    while (j >= 0 && ratings[j] > ratings[j+1] && amount[j] == amount[j+1]) {
                        ++amount[j];
                        ++ans;
                        --j;
                    }
                }
            }

            ans += amount[i];
        }

        return ans;
    }
};

