/*
    Problem: 982. Triples with Bitwise AND Equal To Zero
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int freq[1 << 16];
    int countTriplets(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = 0; j < (int)nums.size(); ++j) {
                ++freq[nums[i] & nums[j]];
            }
        }

        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int v = 0; v < (1 << 16);) {
                int d = nums[i] & v;
                if (d == 0) {
                    ans += freq[v];
                    ++v;
                }
                else {
                    v += (d & -d);
                }
            }
        }

        return ans;
    }
};
