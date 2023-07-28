#include <iostream>
#define MAXN 1000000

long long tnum[MAXN+1];

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    // Precompute the triangular numbers.
    for (int i = 1; i <= MAXN; ++i) {
        tnum[i] = tnum[i-1] + i;
    }

    long long n;

    std::cin >> n;

    /*
        i   0   1   2   3   4   5   6
        a   0   1   0   1   1   2   5
        psa 0   1   1   2   3   5   10
                        ^
            sum = psa[r] - psa[l-1]
            
            for [1, r]:
                if psa[i] is even, check how many even numbers before it
                if psa[i] is odd, check how many odd numbers before it
        
        ans = 0 + 1 + 1 + 2 + 3 + 2
    */

    for (int l = 0, r = MAXN; l <= r; --r) {
        while (tnum[l]+tnum[r] < n) ++l;
        if (tnum[l]+tnum[r] == n) {
            if (l == 0 && r != 0 && l + r <= MAXN) {
                std::cout << r << '\n' << '0';
                for (int j = 1; j < r; ++j) std::cout << " 0";
                std::cout << '\n';
                return 0;
            }
            else if (l + r < MAXN) {
                std::cout << l+r+1 << '\n';
                for (int j = 0; j < l; ++j) std::cout << "0 ";
                std::cout << '1';
                for (int j = 0; j < r; ++j) std::cout << " 0";
                std::cout << '\n';
                return 0;
            }
        }
    }

    std::cout << "-1\n";

    return 0;
}