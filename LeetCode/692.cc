/*
    Problem: 692. Top K Frequent Words
    Diffuculty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second || a.second == b.second && a.first > b.first;
    }
public:
    priority_queue<pair<string, int>, std::vector<pair<string, int>>, decltype(cmp)*> pq{cmp};
    unordered_map<string, int> freq;
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        res.reserve(k);

        for (int i = 0; i < (int)words.size(); ++i) {
            ++freq[words[i]];
        }

        for (const auto &[key, cnt] : freq) {
            pq.push({key, cnt});
        }

        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};

