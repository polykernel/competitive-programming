/*
    Problem: 204. Count Primes
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 5000000;
    int sieve[MAXN+1];
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int count = 1;
        for (int v = 4; v < n; v += 2) {
            sieve[v] = true;
        }

        int i;
        for (i = 3; i * i < n; i += 2) {
            if (!sieve[i]) {
                ++count;
                for (int j = i+i; j < n; j += i) {
                    sieve[j] = true;
                }
            }
        }

        for (; i < n; i += 2) {
            if (!sieve[i]) ++count;
        }

        return count;
    }
};
