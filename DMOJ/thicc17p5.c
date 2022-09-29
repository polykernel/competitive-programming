#include <stdio.h>
#define MAXF 1000000
#define MAXN 100000

int freq[MAXF+1];
int a[MAXN+1];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int count = 0;
    long long ans = 0;

    for (int l = 0, r = 0; r < n; ++r) {
        scanf("%d", &a[r]);

        if (freq[a[r]] == 0) ++count;
        ++freq[a[r]];

        while (count >= k) {
            if (freq[a[l]] == 1) --count;
            --freq[a[l]];
            ++l;
        }

        ans += r - l + 1;
    }

    printf("%lld\n", 1LL*n*(n+1)/2 - ans);

    return 0;
}
