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
    int max_diff;
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        max_diff = 0;
        dfs(root);
        if (max_diff > 1) {
            return false;
        }

        return true;
    }

private:
    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        max_diff = max(max_diff, abs(left - right));

        return 1 + max(left, right);
    }
};
