/*
    CSES Problem Set
    Task: 2165
    Problem: Tower of Hanoi
*/
#include <iostream>

void hanoi(int n, int start, int end, int aux) {
    if (n == 1) {
        std::cout << start << ' ' << end << '\n';
    }
    else {
        hanoi(n-1, start, aux, end);
        std::cout << start << ' ' << end << '\n';
        hanoi(n-1, aux, end, start);
    }
}

int main(void) {
    int n;
    std::cin >> n;

    std::cout << (1 << n) - 1 << '\n';

    hanoi(n, 1, 3, 2);

    return 0;
}
