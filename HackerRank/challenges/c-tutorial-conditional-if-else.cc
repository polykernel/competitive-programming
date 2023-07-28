/*
    Problem: Conditional Statements
    Difficulty: Easy
    Link: https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem
*/
#include <iostream>
#include <cstdio>

using namespace std;

const char* const a[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    int n;
    scanf("%d", &n);

    if (n >= 1 && n <= 9) {
        printf("%s\n", a[n]);
    }
    else {
        printf("Greater than 9\n");
    }

    return 0;
}
