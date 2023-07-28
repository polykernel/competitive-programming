/*
    Problem: 102. Binary Tree Level Order Traversal
    Difficult: Medium
*/
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;

        if (root != NULL) q.push({root, 0});


        while (!q.empty()) {
            auto c = q.front();
            q.pop();

            if (c.second >= res.size()) res.push_back(vector<int>());
            res[c.second].push_back(c.first->val);

            if (c.first->left != NULL) {
                q.push({c.first->left, c.second + 1});
            }
            if (c.first->right != NULL) {
                q.push({c.first->right, c.second + 1});
            }
        }

        return res;
    }
};
