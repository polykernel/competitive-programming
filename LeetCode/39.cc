/*
    Problem: 39. Combination Sum
    Diffuculty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 200;
    int freq[MAXN+1];
    void f(vector<vector<int>>& ans, vector<int>& candidates, int t, int c, int p) {
        if (c == t) {
            vector<int> res;
            for (int i = 1; i <= MAXN; ++i) {
                if (freq[i] > 0) {
                    res.insert(res.end(), freq[i], i);
                }
            }
            ans.push_back(res);
        }
        else {
            for (int i = p; i < (int)candidates.size() && c + candidates[i] <= t; ++i) {
                ++freq[candidates[i]];
                f(ans, candidates, t, c + candidates[i], i);
                --freq[candidates[i]];
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());

        f(ans, candidates, target, 0, 0);

        return ans;
    }
};
