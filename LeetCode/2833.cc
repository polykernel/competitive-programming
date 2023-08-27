/*
    Problem: 2833. Furthest Point From Origin
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int num_l = 0;
        int num_r = 0;
        int num_u = 0;
        
        for (int i = 0; i < moves.length(); i++) {
            switch (moves[i]) {
                case 'L':
                    num_l++;
                    break;
                case 'R':
                    num_r++;
                    break;
                case '_':
                    num_u++;
                    break;
            }
        }
        
        if (num_l > num_r) std::swap(num_l, num_r);
        
        return (num_r - num_l) + num_u;
    }
};