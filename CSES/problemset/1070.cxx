/*
    CSES Problem Set
    Task: 1070
    Problem: Permutation
*/
#include <iostream>

int main(void) {
    int n;
    std::cin >> n;

    // if n == 1, there is the trivial solution
    if (n == 1) {
        std::cout << "1\n";
    }
    // for 1 < n <= 3, no matter how we choose pairs (i, j)
    // i1 j1 i2 ... will always have one adjacent pair with
    // absolute difference of 1.
    else if (n <= 3) {
        std::cout << "NO SOLUTION\n";
    }
    else {
        // chopse pairs (i+2, i) consecutively
        for (int i = 1; i <= n/2; ++i) {
            std::cout << i+n/2 << ' ' << i << ' ';
        }

        if (n % 2 != 0) std::cout << n;

        std::cout << '\n';
    }

    return 0;
}
