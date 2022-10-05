/*
    Problem: 2326. Spiral Matrix IV
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        for (int i = 0; 2*i < m && head != NULL; ++i) {
            for (int v = 0; v <= n-2*i-1 && head != NULL; ++v) {
                matrix[i][i+v] = head->val;
                head = head->next;
            }

            for (int j = 1; j < m-2*i-1 && head != NULL; ++j) {
                matrix[i+j][i+n-2*i-1] = head->val;
                head = head->next;
            }

            for (int v = n-2*i-1; v >= 0 && head != NULL; --v) {
                matrix[i+m-2*i-1][i+v] = head->val;
                head = head->next;
            }

            for (int j = m-2*i-2; j > 0 && head != NULL; --j) {
                matrix[i+j][i] = head->val;
                head = head->next;
            }
        }

        return matrix;
    }
};
