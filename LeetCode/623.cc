/*
    Problem: 623. Add One Row to Tree
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
    void traverse(TreeNode* cur, int val, int cdepth, int tdepth) {
        if (cur == NULL) return;
        if (cdepth + 1 < tdepth) {
            traverse(cur->left, val, cdepth+1, tdepth);
            traverse(cur->right, val, cdepth+1, tdepth);
        }
        else {
            TreeNode* left_node = new TreeNode(val);
            left_node->left = cur->left;

            TreeNode* right_node = new TreeNode(val);
            right_node->right = cur->right;

            cur->left = left_node;
            cur->right = right_node;
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, NULL);
        }
        else {
            traverse(root, val, 1, depth);
            return root;
        }
    }
};
