/*
    Problem: 98. Validate Binary Search Tree
    Difficulty: Medium
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
    bool f(int l, int r, TreeNode* root) {
        if (root == NULL) return true;
        else if (root->val < l || root->val > r) return false;
        else {
            bool res = true;
            if (root->left) {
                if (root->val == INT_MIN) res = false;
                else res = res && f(l, root->val - 1, root->left);
            }
            if (root->right) {
                if (root->val == INT_MAX) res = false;
                else res = res && f(root->val == INT_MAX ? INT_MAX : root->val + 1, r, root->right);
            }
            return res;
        }
    }

    bool isValidBST(TreeNode* root) {
        return f(INT_MIN, INT_MAX, root);
    }
};
