/*
    Problem: 105. Construct Binary Tree from Preorder and Inorder Traversal
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
    static const int MAXN = 30000;
    int pos[2*MAXN+1];

    int f(int j, vector<int>& preorder, int l, int m, int r, TreeNode* tree) {
        int p = j;

        if (l > r) return p;
        if (p < (int)preorder.size() && pos[preorder[p]+MAXN] >= l && pos[preorder[p]+MAXN] < m) {
            tree->left = new TreeNode(preorder[p]);
            p = f(p+1, preorder, l, pos[preorder[p]+MAXN], m-1, tree->left);
        }

        if (p < (int)preorder.size() && pos[preorder[p]+MAXN] > m && pos[preorder[p]+MAXN] <= r) {
            tree->right = new TreeNode(preorder[p]);
            p = f(p+1, preorder, m+1, pos[preorder[p]+MAXN], r, tree->right);
        }

        return p;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res = new TreeNode(preorder[0]);
        int n = inorder.size();

        for (int i = 0; i < n; ++i) {
            pos[MAXN+inorder[i]] = i;
        }

        f(1, preorder, 0, pos[preorder[0]+MAXN], n-1, res);

        return res;
    }
};
