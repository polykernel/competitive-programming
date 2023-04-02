/*
    CSES Problem Set
    Task: 1755
    Problem: Palindrome Reorder
*/
#include <iostream>
#include <string>

int freq[26];

int main(void) {
    std::string s;
    std::cin >> s;

    int n = (int)s.length();

    // TODO: rewrite this section to be more clear
    // Idea: We first partition the letters in the string into
    // histograms. Suppose S = {a : x_1, b : x_2, ...} be the set
    // of pairs denoting letters in the string with their frequency,
    // 
    // Lemma: if S can form a palindrome, then any subset of S can
    // also form a palindrome.
    //
    // A corollary of the contrapostive of the lemma is that the
    // number of letters with odd frequency must be 0 or 1 since the
    // set of two letters with odd frequency which is a subset of S
    // can not form a palindrome.

    int odd_cnt = 0;
    std::string res(n, 0);

    for (char c : s) {
        freq[c-'A']++;
    }

    int l = 0;

    for (int i = 0; i < 26 && odd_cnt <= 1; i++) {
        for (int v = 0; v < freq[i]/2; ++v) {
            res[l] = (char)'A'+i;
            res[n-1-l] = (char)'A'+i;
            l++;
        }
        if (freq[i] % 2 != 0) {
            ++odd_cnt;
            res[n/2] = (char)'A'+i;
        }
    }

    if (odd_cnt > 1) std::cout << "NO SOLUTION\n";
    else std::cout << res << '\n';

    return 0;
}
