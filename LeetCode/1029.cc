/*
    Problem: 1029. Two City Scheduling
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> diff(costs.size());
        int total = 0;

        // the minimum cost = sum(cost[i][0]) - sum(cost[k][0]) + sum(cost[k][1])
        // rearranging, min cost = sum(cost[i][0]) - sum(cost[k][0] - cost[k][1])
        // so we get the minimum cost when sum(cost[k][0] - cost[k][1]) is maximum.
        // We choose the greatest n cost[k][0] - cost[k][1] values and subtract
        // it from sum(cost[i][0]).

        for (int i = 0; i < (int)costs.size(); ++i) {
            total += costs[i][0];
            diff[i] = costs[i][0] - costs[i][1];
        }

        sort(diff.begin(), diff.end(), greater<int>());

        for (int i = 0; i < (int)diff.size()/2; ++i) {
            total -= diff[i];
        }

        return total;
    }
};
