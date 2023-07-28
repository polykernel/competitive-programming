/*
    Problem: 2405. Optimal Partition of String
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

/*
  idea: greedy partitioning, try to extend the current partition
  as much as possible, this is optimal because it performs at least
  as well as splitting the current partition then extending.

  consider a maximal existing parition P

  [ . . . . ] . . . . .
       P

  consider splitting the current partition at some point to Q and R, and
  the maximal extension of R after the split.

  [ . . ] [ . . . . . . ]
    Q             R

  notice, since the second partition starts before the end of P, then
  starting from the end of P to the end of R is a subsegment of R, therefore
  it is a valid partition

  [ . . . . ] [ . . . . ]
       P            P'

  so the number of partitions using both schemes is the same, thus greedy
  partitioning does at least as well as any other partitioning scheme.
*/

class Solution {
public:
    int masks[26];
    int partitionString(string s) {
        int n = (int)s.length();
        int ans = 0;
        int bm = 0;

        masks[0] = 1;
        for (int i = 1; i < 26; i++) {
            masks[i] = masks[i-1] << 1;
        }

        for (int i = 0; i < n; ++i) {
            if (bm & masks[s[i]-'a']) {
                ++ans;
                bm = 0;
            }
            bm |= masks[s[i]-'a'];
        }

        ++ans;

        return ans;
    }
};
