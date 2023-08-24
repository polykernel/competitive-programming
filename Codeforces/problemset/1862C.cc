#include <iostream>
#include <algorithm>
#define MAXN 200000

int a[MAXN];

int bin_search(int v, int n) {
    int l = 0;
    int r = n;

    while (l < r) {
        int m = l+(r-l)/2;
        if (a[m] >= v) {
            l = m + 1;
        }
        else {
            r = m;
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
        int n;
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        bool symmetrical = true;

        for (int i = 0; i < n; i++) {
            int c = bin_search(i+1, n);
            if (a[i] != c) {
                symmetrical = false;
                break;
            }
        }

        if (symmetrical) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}