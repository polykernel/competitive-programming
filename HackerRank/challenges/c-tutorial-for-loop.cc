/*
    Problem: For Loop
    Difficulty: Easy
    Link: https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
*/
#include <iostream>
#include <cstdio>

using namespace std;

const char* const words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; ++i) {
        if (i <= 9) {
            printf("%s\n", words[i]);
        }
        else if (i % 2 == 0) {
            printf("even\n");
        }
        else {
            printf("odd\n");
        }
    }

    return 0;
}
