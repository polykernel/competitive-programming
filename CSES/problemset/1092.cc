/*
    CSES Problem Set
    Task: 1092
    Problem: Two Sets
*/
#include <iostream>
#include <vector>

std::vector<int> a;
std::vector<int> b;

int main(void) {
    int n;
    std::cin >> n;

    long long sum = 1LL*n*(n+1)/2;

    if (sum % 2 != 0) {
        std::cout << "NO\n";
    }
    else {
        long long total = 0;
        int i;
        for (i = n; i >= 1 && total < sum/2; --i) {
            if (total + i <= sum/2) {
                total += i;
                a.push_back(i);
            }
            else {
                b.push_back(i);
            }
        }

        while (i >= 1) {
            b.push_back(i);
            --i;
        }

        std::cout << "YES\n";

        std::cout << (int)a.size() << '\n';
        for (const int x : a) {
            std::cout << x << ' ';
        }
        std::cout << '\n';

        std::cout << (int)b.size() << '\n';
        for (const int y : b) {
            std::cout << y << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
