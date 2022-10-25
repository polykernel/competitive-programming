/*
    CSES Problem Set
    Task: 1069
    Problem: Repetition
*/
#include <iostream>
#include <string>

int main(void) {
    std::string s;
    std::cin >> s;

    int ans = 0;
    int lc = 0;

    for (int i = 1; i < (int)s.length(); ++i) {
        if (s[i] != s[i-1]) {
            ans = std::max(ans, i - lc);
            lc = i;
        }
    }

    ans = std::max(ans, (int)s.length() - lc);

    std::cout << ans << '\n';

    return 0;
}
