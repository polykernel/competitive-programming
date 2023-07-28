#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

typedef long long ll;

const int MODN = 1'000'000'007;
const int BASE1 = 131;
const int BASE2 = 10'007;
const int MAXN = 200'000;

ll pw1[MAXN+1];
ll pw2[MAXN+1];
ll hash1[MAXN+1];
ll hash2[MAXN+1];
std::vector<int> freqs(26);
std::vector<int> freqt(26);
std::unordered_set<ll> st;

ll getsubhash(int l, int r) {
    ll v1 = (hash1[r] - hash1[l-1]*pw1[r-l+1] % MODN + MODN) % MODN;
    ll v2 = (hash2[r] - hash2[l-1]*pw2[r-l+1] % MODN + MODN) % MODN;
    return (v1 << 32) | v2;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string s, t;
    std::cin >> s >> t;

    int n = (int)s.length();
    int m = (int)t.length();

    for (char c : s) ++freqs[c-'a'];

    pw1[0] = 1;
    pw2[0] = 1;

    for (int i = 1; i <= m; ++i) {
        pw1[i] = pw1[i-1] * BASE1 % MODN;
        hash1[i] = (hash1[i-1] * BASE1 + t[i-1]) % MODN;
        pw2[i] = pw2[i-1] * BASE2 % MODN;
        hash2[i] = (hash2[i-1] * BASE2 + t[i-1]) % MODN;
    }

    for (int i = 1; i <= m; ++i) {
        ++freqt[t[i-1]-'a'];
        if (i > n) --freqt[t[i-n-1]-'a'];
        if (freqs == freqt) st.insert(getsubhash(i-n+1, i));
    }

    std::cout << st.size() << '\n';

    return 0;
}
