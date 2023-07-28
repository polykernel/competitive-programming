/*
    Problem: 28. Find the Index of the First Occurrence in a String
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MODN = 1000000009;
    int strStr(string haystack, string needle) {
        int p = 31;
        int n = haystack.length();
        int m = needle.length();
        vector<long long> hash(n+1, 0);
        vector<long long> ppow(max(n, m), 0);
        ppow[0] = 1;

        if (m == 0) return 0;

        for (int i = 1; i < (int)ppow.size(); ++i) {
            ppow[i] = (ppow[i-1] * p) % MODN;
        }

        for (int i = 0; i < n; ++i) {
            hash[i+1] = (hash[i] + (haystack[i]  - 'a' + 1) * ppow[i]) % MODN;
        }

        long long needle_hash = 0;
        for (int i = 0; i < m; ++i) {
            needle_hash = (needle_hash + (needle[i] - 'a' + 1) * ppow[i]) % MODN;
        }

        for (int i = 0; i <= n-m; ++i) {
            long long x = (hash[i+m] - hash[i] + MODN) % MODN;
            if (x == needle_hash * ppow[i] % MODN) {
                bool flag = true;
                for (int v = 0; v < m; ++v) {
                    if (haystack[i+v] != needle[v]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return i;
            }
        }

        return -1;
    }
};

int main() {
    auto tester = Solution();

    cout << tester.strStr("bob the builder", "builder") << '\n';
}
