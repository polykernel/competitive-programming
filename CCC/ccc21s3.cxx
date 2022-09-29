#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long ll;
typedef std::pair<int, int> pii;

const int MAXN = 200'000;

int p[MAXN+1];
int w[MAXN+1];
int d[MAXN+1];
std::vector<pii> points;
ll dy;
int n;

ll walking_time(int pos) {
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        if (abs(p[i] - pos) > d[i]) {
            res += 1LL*w[i]*std::min(abs(pos - (p[i]-d[i])), abs(pos - (p[i]+d[i])));
        }
    }
    return res;
}

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i] >> w[i] >> d[i];
        dy -= w[i];
        points.push_back({p[i] - d[i], w[i]});
        points.push_back({p[i] + d[i], w[i]});
    }

    std::sort(points.begin(), points.end());

    for (pii curr : points) {
        dy += curr.second;
        if (dy >= 0) {
            std::cout << walking_time(curr.first) << '\n';
            break;
        }
    }

    return 0;
}
