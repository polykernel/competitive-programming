/*
    Problem: 122. Best Time to Buy and Sell Stock II
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int lowest_price = INT_MAX;
        int highest_price = 0;

        for (int i = 0; i < (int)prices.size(); ++i) {
            if (prices[i] >= highest_price) {
                highest_price = prices[i];
            }
            else {
                profit += highest_price - lowest_price;
                lowest_price = prices[i];
                highest_price = prices[i];
            }
            if (prices[i] < lowest_price) {
                lowest_price = prices[i];
            }
        }

        profit += highest_price - lowest_price;

        return profit;
    }
};
