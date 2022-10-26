/*
    CSES Problem Set
    Task: 1072
    Problem: Two Knights
*/
#include <iostream>
#include <cstring>

constexpr int MAXN = 10000;

int dp[MAXN+1];
int tmp[MAXN+1];

long long nc2(int n) { return 1LL*n*(n-1)/2; }

int main(void) {
    int n;
    std::cin >> n;

    // idea: we can count the number of pairs of points in a mxn grid
    // that are one knight hop away(say Sn), then the number of ways to place
    // two knights such that they are not one hop away is m*n choose 2 - Sn

    // we can compute the number of knight hop pairs recursively
    // let Sn,m be the number of knight hop pairs in a nxm grid
    // then Sn,m = Sn-1,m + Sn,m-1 - Sn-1,m-1 + k
    // where
    // k = 0, if neither n or m are greater or equal than 3
    // (in this case, the corner point at coordinate (n, m) can not pair with any
    // point, similarly (n-1, m) can not pair with (n, m-2), and (n, m-1) can not pair
    // with (n-2, m))
    // k = 2, if one of n and m is greater or equal to 3
    // (in this case, the corner point at coordinate (n, m) can pair with one point
    // and one of (n-1, m), (n, m-1) can pair with one point)
    // k = 4, if both n and m are greater or equal to 3
    // (in this case, the corner point at coordinate (n, m) can pair with two points
    // and both (n-1, m), (n, m-1) can pair with one point)
    // This gives us the dynamic programming transition: dp[n][m] = dp[n-1][m] + dp[n][m-1] - dp[n-1][m-1] + k
    // since we need to iterate n and m, this results in O(n^2) time complexity.

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int k = 0;
            if (j >= 2 && i >= 3) k += 2;
            if (i >= 2 && j >= 3) k += 2;

            if (i == j) {
                dp[j] = 2*dp[j] - tmp[j-1] + k;
                std::cout << nc2(i*i) - dp[j] << '\n';
            }
            else {
                dp[j] = dp[j] + dp[j-1] - tmp[j-1] + k;
            }
        }
        memcpy(tmp, dp, sizeof(dp));
    }

    return 0;
}
