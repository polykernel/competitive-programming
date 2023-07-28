/*
    Problem: 823. Binary Trees With Factors
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 1000;
    static const int MODN = 1000000007;
    int dp[MAXN+1];
    unordered_map<int, int> imap;

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        for (int i = 0; i < (int)arr.size(); ++i) {
            dp[i] = 1;
            imap[arr[i]] = i;
            for (int v = 0; v < i; ++v) {
                if (1LL * arr[v] * arr[v] > 1LL * arr[i]) break;
                if (arr[i] % arr[v] == 0) {
                    int k = arr[i] / arr[v];
                    if (imap.count(k) > 0) {
                        if (arr[v] == k) dp[i] = (1LL * dp[i] + (1LL * dp[v] * dp[imap[k]] % MODN)) % MODN;
                        else dp[i] = (1LL * dp[i] + (2LL * dp[v] * dp[imap[k]] % MODN)) % MODN;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < (int)arr.size(); ++i) {
            ans = (1LL * ans + dp[i]) % MODN;
        }

        return ans;
    }
};
