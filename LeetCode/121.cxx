/*
    Problem: 121. Best Time to Buy and Sell Stock
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int INF = 0x3f3f3f3f;
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_price = INF;

        for (int i = 0; i < (int)prices.size(); ++i) {
            ans = max(ans, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }

        return ans;
    }
};
