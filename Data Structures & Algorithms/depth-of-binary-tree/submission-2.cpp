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

        int depth = 0;
        queue<TreeNode *> node_q;
        node_q.push(root);
        while (!node_q.empty()) {
            int size = static_cast<int>(node_q.size());
            for (int i = 0; i < size; i++) {
                TreeNode *node = node_q.front();
                node_q.pop();
                if (node->left) node_q.push(node->left);
                if (node->right) node_q.push(node->right);
            }
            depth++;
        }

        return depth; 
    }
};
