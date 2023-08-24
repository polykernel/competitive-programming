#include <iostream>
#define INF 0x3f3f3f3f
#define MAXN 20

int grid[MAXN];
std::string s = "vika";

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int k = 0; k < t; k++) {
        int n, m;
        std::cin >> n >> m;

        std::fill(grid, grid+MAXN, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                std::cin >> c;

                grid[j] |= 1 << (c - 'a');
            }
        }

        bool valid = true;


        for (int j = 0, x = 0; x < (int)s.length(); x++, j++) {
            while (j < m && (grid[j] & (1 << (s[x] - 'a'))) == 0) ++j;

            if (j >= m) {
                valid = false;
                break;
            }
        }

        if (valid) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}