/*
    Problemset: 1745
    Problem: B. Kevin and Permutation
    Link: https://codeforces.com/problemset/problem/1754/B
*/
#include <bits/stdc++.h>

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;

        for (int j = 0; j < n/2; ++j) {
            std::cout << ((n+1)/2 - j) << ' ' << (n-j) << ' ';
        }

        if (n % 2 != 0) std::cout << "1\n";
        else std::cout << '\n';
    }

    return 0;
}
