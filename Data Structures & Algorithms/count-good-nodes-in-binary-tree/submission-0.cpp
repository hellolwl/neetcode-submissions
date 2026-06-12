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
    int count;
public:
    int goodNodes(TreeNode* root) {
        count = 0;
        dfs(root, root->val);

        return count;
    }

private:
    void dfs(TreeNode *node, int curr_max) {
        if (node == nullptr) {
            return;
        }

        if (node->val >= curr_max) {
            count++;
        }

        int new_max = max(node->val, curr_max);
        dfs(node->left, new_max);
        dfs(node->right, new_max);
    }
};
