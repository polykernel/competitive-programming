/*
    Contest: Project Euler
    Problem: 1. Multiples of 3 or 5
    Difficulty: Easy
    Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i){
        int n;
        cin >> n;

        int multiple3 = (n-1)/3;
        long long sum3 = 3LL * (1LL * multiple3 * (1 + multiple3) / 2);
        int multiple5 = (n-1)/5;
        long long sum5 = 5LL * (1LL * multiple5 * (1 + multiple5) / 2);
        int multiple15 = (n-1)/15;
        long long sum15 = 15LL * (1LL * multiple15 * (1 + multiple15) / 2);

        cout << sum3 + sum5 - sum15 << '\n';
    }
    return 0;
}
