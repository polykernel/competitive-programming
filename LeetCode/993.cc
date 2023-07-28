/*
    Problem: 993. Cousins in Binary Tree
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
    static constexpr int MAXN = 100;
    int depth[MAXN+1];
    int prev[MAXN+1];

    void dfs(TreeNode* u) {
        if (u->left != NULL) {
            depth[u->left->val] = depth[u->val] + 1;
            prev[u->left->val] = u->val;
            dfs(u->left);
        }
        if (u->right != NULL) {
            depth[u->right->val] = depth[u->val] + 1;
            prev[u->right->val] = u->val;
            dfs(u->right);
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        depth[root->val] = 0;
        prev[root->val] = -1;
        dfs(root);

        return depth[x] == depth[y] && prev[x] != prev[y];
    }
};
