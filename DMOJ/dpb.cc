#include <iostream>
#define MAXN 100000
#define INF 0x3f3f3f3f

int hops[MAXN+1];
int stone[MAXN+1];

int abs(int x) { return x >= 0 ? x : -x; }

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, k;

    std::cin >> n >> k;

    std::cin >> stone[1];
    hops[1] = 0;

    for (int i = 2; i <= n; ++i) {
        std::cin >> stone[i];
        hops[i] = INF;
        for (int j = 1; j <= k; ++j) {
            if (j < i) {
                hops[i] = std::min(hops[i], hops[i-j]+abs(stone[i]-stone[i-j]));
            }
        }
    }
    
    std::cout << hops[n] << '\n';

    return 0;
}