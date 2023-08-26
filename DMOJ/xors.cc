#include <iostream>

int main() {
    int n;
    std::cin >> n;

    /*
        Proposition 1: x + y >= x ^ y for all x, y >= 0
        
        Let x_0 be the sum of the a_i with m add and k xor.
        Let x be the sum of the a_i with n add and 0 xor.
        By proposition 1, we have x >= x_0, since 0 <= k
        and the associtivity of addition. Therfore x is
        the maximal sum of the a_i.

        Let y_0 be the sum of the a_i with m add and k xor.
        Let y be the sum of the a_i with 0 add and n xor.
        By proposition 1, we have y <= y_0, since 0 <= m
        and the associtivity of xor. Therfore y is the
        minimal sum of the a_i.
    */
    long long mx_sum = 0;
    long long mn_sum = 0;

    for (int i = 1; i <= n; i++) {
        long long x;
        std::cin >> x;

        mx_sum += x;
        mn_sum ^= x;
    }

    std::cout << mx_sum - mn_sum << '\n';

    return 0;
}