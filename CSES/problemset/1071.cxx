/*
    CSES Problem Set
    Task: 1071
    Problem: Number Spiral
*/
#include <iostream>

int main(void) {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int r, c;
        std::cin >> r >> c;

        if (r < c) {
            if (c % 2 == 0) std::cout << 1LL*(c-1)*(c-1) + r << '\n';
            else std::cout << 1LL*c*c - r + 1 << '\n';
        }
        else {
            if (r % 2 != 0) std::cout << 1LL*(r-1)*(r-1) + c << '\n';
            else std::cout << 1LL*r*r - c + 1 << '\n';
        }
    }

    return 0;
}
