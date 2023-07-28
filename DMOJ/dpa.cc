#include <iostream>
#define MAXN 100000
#define INF 0x3f3f3f3f

int hops[MAXN+1];
int stone[MAXN+1];

int abs(int x) { return x >= 0 ? x : -x; }

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n;

    std::cin >> n;

    std::cin >> stone[1];
    hops[1] = 0;

    // H(x) = min(H(x-2)+abs(W(x)-W(x-2), H(x-1)+abs(W(x)-W(x-1)))
    for (int i = 2; i <= n; ++i) {
        std::cin >> stone[i];
        hops[i] = INF;
        if (i > 1) hops[i] = std::min(hops[i], hops[i-1]+abs(stone[i]-stone[i-1]));
        if (i > 2) hops[i] = std::min(hops[i], hops[i-2]+abs(stone[i]-stone[i-2]));
    }
    
    std::cout << hops[n] << '\n';

    return 0;
}