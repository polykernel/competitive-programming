#include <iostream>
#define MAXC 2000000000

int bin_search(long long v, int max) {
    int l = 1;
    int r = max;

    while (l < r) {
        int m = l+(r-l+1)/2;
        long long tri = 1LL * m * (m-1) / 2;
        if (tri <= v) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }

    return l;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int k = 0; k < t; k++) {
        long long n;
        std::cin >> n;

        // total balls = n distinct balls + m duplicate balls (0 <= m < n)
        // the number of cones that can be made from n distinct balls is
        // n * (n-1) / 2, since the difference between conseuctive triangular
        // numbers is n, less than n duplicate balls always suffice.
        int dc = bin_search(n, MAXC);
        long long total = dc + (n - 1LL * dc * (dc-1) / 2);

        std::cout << total << '\n';
    }
}