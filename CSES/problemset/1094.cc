/*
    CSES Problem Set
    Task: 1094
    Problem: Increasing Array
*/
#include <iostream>

int main(void) {
    int n;
    std::cin >> n;

    long long ans = 0;

    int p;
    std::cin >> p;

    for (int i = 1; i < n; ++i) {
        int k;
        std::cin >> k;

        if (k < p) ans += p - k;
        else if (k > p) p = k;
    }

    std::cout << ans << '\n';

    return 0;
}
