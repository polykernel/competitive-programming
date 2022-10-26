/*
    CSES Problem Set
    Task: 1617
    Problem: Bit Strings
*/
#include <iostream>

constexpr int MODN = 1000000007;

int bin_pow(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    int res = bin_pow(x, n/2);
    res = (1LL*res*res) % MODN;

    if (n % 2 != 0) res = (1LL*res*x) % MODN;

    return res;
}

int main(void) {
    int n;
    std::cin >> n;

    std::cout << bin_pow(2, n) << '\n';

    return 0;
}
