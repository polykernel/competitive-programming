/*
    Problem: 2829. Determine the Minimum Sum of a k-avoiding Array
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0;
        int bp = k / 2;
        if (n > bp) {
            n -= bp;
            sum += ((bp+1) * bp + (2*k+n-1) * n) / 2;
        }
        else {
            sum += (n+1) * n / 2;
        }
        return sum;
    }
};
