#include <iostream>
#define MAXN 25

int cats[MAXN+1][MAXN+1];
int dp[MAXN+1][MAXN+1];

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    dp[0][1] = 1;

    int r, c;
    int k;

    std::cin >> r >> c;

    std::cin >> k;

    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;
        cats[x][y] = true;
    }

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (!cats[i][j]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    std::cout << dp[r][c] << '\n';

    return 0;
}