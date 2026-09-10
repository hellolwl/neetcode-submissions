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
private:
    int result;

    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        result = max(result, left_depth + right_depth);

        return 1 + max(left_depth, right_depth);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        result = 0;

        maxDepth(root);

        return result;
    }
};
