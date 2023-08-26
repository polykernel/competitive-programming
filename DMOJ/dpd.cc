#include <iostream>
#include <algorithm>
#define MAXW 100000

long long dp[MAXW+1]; // dp[weight w]: max value of knapsack with weight w

int main() {
    int n, w;
    std::cin >> n >> w;

    for (int i = 1; i <= n; i++) {
        int w_i, v_i;
        std::cin >> w_i >> v_i;

        for (int j = w; j >= w_i; j--) {
            dp[j] = std::max(dp[j], dp[j-w_i] + v_i);
        }
    }

    std::cout << dp[w] << '\n';

    return 0;
}