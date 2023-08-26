#include <iostream>

int main() {
    int t;
    std::cin >> t;

    /*
        Given a grid with n rows and m columns,
        We know conseuctive numbers are coprime
        so lets zigzag vertically with 2 as the first
        number and 1 as the last number like the following
        2  3  4  5  6        2  -> -> -> v
        11 10 9  8           v  <- <- <- <-
        12 13 14 15 16       .  .  .  .  .
        1  20 19 18 17       1  <- <- <- <-

        the number underneath 2 is always odd because its
        value is either 2 + (2m - 1) is n > 2 or 1 if n = 2.

        edge cases:
        1) n = 1 or m = 1, it is impossible to satisfy the constraint
        since the first and last cell only has one neighbour.
    */

    for (int k = 0; k < t; k++) {
        int n, m;
        std::cin >> n >> m;

        if (n == 1 || m == 1) {
            std::cout << "-1\n";
            continue;
        }

        int num = 2;

        for (int i = 0; i < n-1; i++) {
            if (i & 1) {
                for (int v = m-1; v >= 0; v--) {
                    std::cout << num + v << ' ';
                }
            }
            else {
                for (int v = 0; v < m; v++) {
                    std::cout << num + v << ' ';
                }
            }
            std::cout << '\n';
            num += m;
        }

        if (n & 1) {
            for (int v = 0; v < m - 1; v++) {
                std::cout << num + v << ' ';
            }
            std::cout << "1 ";
        }
        else {
            std::cout << "1 ";
            for (int v = m-2; v >= 0; v--) {
                std::cout << num + v << ' ';
            }
        }
        std::cout << '\n';
        num += m - 2;
    }

    return 0;
}