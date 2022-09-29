#include <iostream>
#include <algorithm>

typedef long long ll;

const int MAXN = 1'000'000;

int point[2*MAXN]; // linearize the circle
int freq[2*MAXN]; // track frequency of each point

ll nchoose2(int n);

inline ll nchoose2(int n) { return 1LL*n*(n-1)/2; }

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, c;
    std::cin >> n >> c;

    for (int i = 0; i < n; ++i) {
        std::cin >> point[i];
        point[i+n] = point[i] + c;
        ++freq[point[i]];
    }

    std::sort(p, p+2*n);

    ll ans = 1LL*n*(n-1)*(n-2)/6;

    int i = 1;
    int j = 1;

    while (i <= n; ++i) {
        while (2*(p[j] - p[i]) <= c) ++j;
        ans -= nchoose2(j-i-1));
    }

    // correct overcounting
    if (c % 2 == 0) {
        for (int i = c/2; i < c; ++i) {
            ans += freq[i] * nchoose2(freq[i-c/2]) + nchoose(freq[i]) * freq[i-c/2];
        }
    }

    std::cout << ans << '\n';

    return 0;
}
