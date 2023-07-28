/*
    Problem: 113. Path Sum II
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
    void dfs(vector<vector<int>>& paths, vector<int>& path, TreeNode* root, int sum) {
        if (root == NULL) return;

        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL && root->val == sum) {
            paths.push_back(path);
        }
        else {
            if (root->left != NULL) dfs(paths, path, root->left, sum - root->val);
            if (root->right != NULL) dfs(paths, path, root->right, sum - root->val);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;

        dfs(paths, path, root, targetSum);

        return paths;
    }
};
