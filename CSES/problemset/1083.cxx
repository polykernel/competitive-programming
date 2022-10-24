/*
    CSES Problem Set
    Task: 1083
    Problem: Missing Number
*/
#include <iostream>

int main(void) {
    int n;
    std::cin >> n;

    long long ans = n;

    for (int i = 1; i < n; ++i) {
        int k;
        std::cin >> k;
        ans += i - k;
    }

    std::cout << ans << '\n';

    return 0;
}
