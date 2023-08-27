/*
    Problem: 2834. Find the Minimum Possible Sum of a Beautiful Array
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // NOTE: essentially a duplicate of 2829
    long long minimumPossibleSum(int n, int target) {
        int k = std::min(n, target / 2);
        long long sum = 1LL * k * (k+1) / 2;
        
        if (n > k) {
            n -= k;
            sum += 1LL * (2 * target + n - 1) * n / 2;
        }
        
        return sum;
    }
};