/*
    Problem: 257. Binary Tree Paths
    Difficulty: Easy
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
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<pair<TreeNode*, string>> q;
        vector<string> ans;

        q.push({root, to_string(root->val)});

        while (!q.empty()) {
            auto [c, s] = q.front();
            q.pop();

            if (c->left == NULL && c->right == NULL) {
                ans.push_back(s);
            }

            if (c->left != NULL) {
                q.push({c->left, s + "->" + to_string(c->left->val)});
            }
            if (c->right != NULL) {
                q.push({c->right, s + "->" + to_string(c->right->val)});
            }
        }

        return ans;
    }
};
