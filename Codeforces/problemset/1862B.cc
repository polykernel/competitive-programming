#include <iostream>
#define MAXN 200000

int seq[2*MAXN];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int k = 0; k < t; k++) {
        int n;
        std::cin >> n;

        int last = 0;
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            int b;
            std::cin >> b;

            if (b >= last) {
                seq[cnt] = b;
                cnt++;
            }
            else {
                seq[cnt] = b;
                cnt++;
                seq[cnt] = b;
                cnt++;
            }
            last = b;
        }

        std::cout << cnt << '\n';

        for (int i = 0; i < cnt; i++) {
            std::cout << seq[i] << ' ';
        }

        std::cout << '\n';
    }
}