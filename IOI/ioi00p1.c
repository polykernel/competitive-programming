#include <stdio.h>
#include <string.h>
#define MAXN 5000

int dp[2][MAXN+1]; // the minimal number of insertions to turn substring i..j into a palindrome
int tmp[MAXN+1]; // swap buffer

int min(int x, int y);

inline int min(int x, int y) { return x > y ? y : x; }

int main(void) {
    int n;
    scanf("%d", &n);

    char s[MAXN+1];
    scanf("%s", s);

    for (int v = 1; v < n; ++v) {
        memcpy(tmp, dp[1], sizeof(int) * (MAXN+1));
        for (int i = n-1; i - v >= 0; --i) {
            if (s[i-v] == s[i]) dp[1][i] = dp[0][i-1];
            else dp[1][i] = min(dp[1][i], dp[1][i-1]) + 1;
        }
        memcpy(dp[0], tmp, sizeof(int) * (MAXN+1));
    }

    printf("%d\n", dp[1][n-1]);

    return 0;
}
