/*
    Problem: 1207. Unique Number of Occurences
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int MAXN = 1000;
    static const int MAXA = 2000;
    int freq[MAXA+1];
    bool vst[MAXN+1];

    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> fv;

        for (int i = 0; i < (int)arr.size(); ++i) {
            if (++freq[arr[i]+1000] == 1) fv.push_back(arr[i]+1000);
        }

        for (int i = 0; i < (int)fv.size(); ++i) {
            if (vst[freq[fv[i]]]) return false;
            else vst[freq[fv[i]]] = true;
        }

        return true;
    }
};
