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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> node_q;
        vector<int> result;

        if (root != nullptr) {
            node_q.push(root);
        }
        while (!node_q.empty()) {
            int q_size = node_q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode *node = node_q.front();
                node_q.pop();
                if (i == q_size - 1) {
                    result.push_back(node->val);
                }

                if (node->left != nullptr) {
                    node_q.push(node->left);
                }
                if (node->right != nullptr) {
                    node_q.push(node->right);
                }
            }
        }

        return result;        
    }
};
