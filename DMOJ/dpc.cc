#include <iostream>
#include <algorithm>
#define MAXN 100000

int dp[3][MAXN+1]; // dp[last day doing activity 0/1/2][first i days]: max points of happiness
int activity[3][MAXN+1];

int main() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> activity[0][i] >> activity[1][i] >> activity[2][i];
    }

    // first day
    dp[0][1] = activity[0][1];
    dp[1][1] = activity[1][1];
    dp[2][1] = activity[2][1];

    for (int i = 2; i <= n; i++) {
        dp[0][i] = std::max(dp[1][i-1], dp[2][i-1]) + activity[0][i];
        dp[1][i] = std::max(dp[0][i-1], dp[2][i-1]) + activity[1][i];
        dp[2][i] = std::max(dp[0][i-1], dp[1][i-1]) + activity[2][i];
    }

    std::cout << std::max({dp[0][n], dp[1][n], dp[2][n]}) << '\n';

    return 0;
}