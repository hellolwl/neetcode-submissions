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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        } else {
            int l_depth = 0;
            int r_depth = 0;
            if (root->left != nullptr) {
                l_depth = maxDepth(root->left);
            }
            if (root->right != nullptr) {
                r_depth = maxDepth(root->right);
            }
                      
            return 1 + max(l_depth, r_depth);
        }
    }
};