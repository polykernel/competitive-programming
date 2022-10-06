/*
    Problem: 981. Time Based Key-Value Store
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> tmap;
public:
    TimeMap() : tmap() {}

    void set(string key, string value, int timestamp) {
        tmap[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (tmap.find(key) == tmap.end() || tmap[key][0].second > timestamp) return "";

        int l = 0;
        int h = (int)tmap[key].size();

        while (l < h) {
            int m = l+(h-l)/2;
            if (tmap[key][m].second <= timestamp) {
                l = m + 1;
            }
            else {
                h = m;
            }
        }

        return tmap[key][l-1].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
