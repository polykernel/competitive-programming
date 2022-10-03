/*
    Problem: 929. Unique Email Addresses
    Difficulty: Easy
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<string> email_set;

    int numUniqueEmails(vector<string>& emails) {
        for (int i = 0; i < (int)emails.size(); ++i) {
            string norm;
            int plus_index = -1;
            int at_index = -1;

            for (int v = 0; v < (int)emails[i].length(); ++v) {
                if (at_index == -1) {
                    switch (emails[i][v]) {
                        case '.':
                            break;
                        case '+':
                            plus_index = v;
                            break;
                        case '@':
                            at_index = v;
                            norm.push_back(emails[i][v]);
                            break;
                        default:
                            if (plus_index == -1) norm.push_back(emails[i][v]);
                            break;
                    }
                }
                else {
                    norm.push_back(emails[i][v]);
                }
            }

            email_set.insert(norm);
        }

        return email_set.size();
    }
};
