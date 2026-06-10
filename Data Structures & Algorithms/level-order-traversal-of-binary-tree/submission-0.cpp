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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode* > node_q;

        if (root) {
            node_q.push(root);
        }
        while (!node_q.empty()) {
            vector<int> row;
            int count = node_q.size();
            for (int i = 0; i < count; i++) {
                TreeNode *node = node_q.front();
                node_q.pop();
                row.push_back(node->val);
                
                if (node->left) {
                    node_q.push(node->left);
                }
                if (node->right) {
                    node_q.push(node->right);
                }
            }

            result.push_back(row);
        }

        return result;
    }
};
