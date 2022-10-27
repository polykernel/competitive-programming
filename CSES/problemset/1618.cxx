/*
    CSES Problem Set
    Task: 1618
    Problem: Trailing Zeros
*/
#include <iostream>

int main(void) {
    int n;
    std::cin >> n;

    // idea: the number of trailing zeros in the factorial n!
    // is the number of 10s we have in the product of n!.
    // This is the same thing as finding the minimum of the number
    // of 2s and the number of 5s. In fact, we know for every increment
    // of 5, we have at least two multiple of 2, the frequency of multiples
    // of 5 is less than the frequency of multiples of 2. Therefore, the
    // minimum number is always the number of 5s.

    int cnt = 0;
    int d = 5;

    while (n / d) {
        cnt += n / d;
        d *= 5;
    }

    std::cout << cnt << '\n';

    return 0;
}
