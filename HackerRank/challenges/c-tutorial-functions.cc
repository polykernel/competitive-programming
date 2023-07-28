/*
    Problem: Functions
    Difficulty: Easy
    Link: https://www.hackerrank.com/challenges/c-tutorial-functions/problem
*/
#include <iostream>
#include <cstdio>

using namespace std;

int max_of_four(int a, int b, int c, int d) {
    int cm = a;

    if (b > cm) cm = b;
    if (c > cm) cm = c;
    if (d > cm) cm = d;

    return cm;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int ans = max_of_four(a, b, c, d);
    printf("%d\n", ans);

    return 0;
}
