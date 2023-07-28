/*
    Problem: 20. Valid Parentheses
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        for (int i = 0; i < (int)s.length(); ++i) {
            if (st.empty()) {
                if (s[i] == ']' || s[i] == ')' || s[i] == '}') return false;
                else st.push(s[i]);
            }
            else {
                char x = st.top();
                if ((x == '(' && s[i] == ')') || (x == '[' && s[i] == ']') || (x == '{' && s[i] == '}')) st.pop();
                else st.push(s[i]);
            }
        }

        return st.empty();
    }
};
