/*
    CSES Problem Set
    Task: 1068
    Problem: Weird Algorithm
*/
#include <iostream>

int main(void) {
    long long n;
    std::cin >> n;

    std::cout << n;

    while (n > 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3*n+1;
        std::cout << ' ' << n;
    };

    std::cout << '\n';

    return 0;
}
