#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        long long p;
        std::cin >> a >> b >> p;

        if (1LL * a * b != p) {
            std::cout << "16 BIT S/W ONLY\n";
        }
        else {
            std::cout << "POSSIBLE DOUBLE SIGMA\n";
        }
    }

    return 0;
}