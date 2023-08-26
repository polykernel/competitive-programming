#include <iostream>
#include <algorithm>
#define MAXN 100
#define MAXV 1000
#define INF 0x3f3f3f3f

int dp[MAXN*MAXV+1]; // dp[value v]: min weight of a knapsack with value v
int weight[MAXN+1];
int value[MAXN+1];

int main() {
    int n, w;
    std::cin >> n >> w;

    int max_v = 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> weight[i] >> value[i];
        
        max_v += value[i];
    }

    std::fill(dp, dp+max_v+1, INF);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = max_v; j >= value[i]; --j) {
            dp[j] = std::min(dp[j], dp[j-value[i]] + weight[i]);
        }
    }

    int ans = max_v;
    while (dp[ans] > w) --ans;

    std::cout << ans << '\n';

    return 0;

}