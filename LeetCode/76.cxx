/*
    Problem: 76. Minimum Window Substring
    Difficulty: Hard
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool cmap[64];
    int freq[64];
    string minWindow(string s, string t) {
        int cnt = 0;
        string res = "";

        for (int i = 0; i < (int)t.length(); ++i) {
            if (!cmap[t[i]-'A']) {
                cmap[t[i]-'A'] = true;
                ++cnt;
            }
            ++freq[t[i]-'A'];
        }

        for (int l = 0, r = 0; r < (int)s.length();) {
            while (r < (int)s.length() && cnt > 0) {
                if (cmap[s[r]-'A']) {
                    --freq[s[r]-'A'];
                    if (freq[s[r]-'A'] == 0) --cnt;
                }
                ++r;
            }

            while (l < r && cnt == 0) {
                if (cmap[s[l]-'A']) {
                    if (freq[s[l]-'A'] == 0) break;
                    ++freq[s[l]-'A'];
                }
                ++l;
            }

            if (cnt == 0 && (res == "" || r - l < (int)res.length())) res = s.substr(l, r-l);

            ++freq[s[l]-'A'];
            ++cnt;
            ++l;
        }

        return res;
    }
};
