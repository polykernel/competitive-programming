/*
    Problem: 199. Binary Tree Right Side View
    Difficulty: Medium
*/
#include <bits/stdc++.h>

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
    void f(vector<int>& v, TreeNode* root, int depth) {
        if (root == NULL) return;

        if (depth == (int)v.size()) {
            v.push_back(root->val);
        }

        f(v, root->right, depth+1);
        f(v, root->left, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        f(res, root, 0);
        return res;
    }
};
