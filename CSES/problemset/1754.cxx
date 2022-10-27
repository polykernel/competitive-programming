/*
    CSES Problem Set
    Task: 1754
    Problem: Coin Piles
*/
#include <iostream>

int main(void) {
    int t;
    std::cin >> t;

    // idea: instead of thinking emptying the two piles,
    // think about how to construct pile (a, b) from (0, 0).
    // At each step, we either add (1, 2) or (2, 1), so
    // then (a, b) = m(1, 2) + n(2, 1). This is simply a system of
    // linear equations in 2 variables! Solving the corresponding
    // matrix gives us the unique solution m = (2b-a)/3, n = (2a-b)/3
    // since m, n are natural numbers, there is a solution if 2b >= a
    // and 2a >= b and both are divisible by 3.

    for (int i = 0; i < t; ++i) {
        int a, b;
        std::cin >> a >> b;

        int d1 = 2*a - b;
        int d2 = 2*b - a;

        if (d1 >= 0 && d1 % 3 == 0 && d2 >= 0 && d2 % 3 == 0) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
