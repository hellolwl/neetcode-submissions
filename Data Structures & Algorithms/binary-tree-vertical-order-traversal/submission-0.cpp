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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        unordered_map<int, vector<int>> columns;
        queue<pair<TreeNode *, int>> nodes_q;
        int min_col = 0;
        int max_col = 0;

        nodes_q.push({root, 0});

        while (!nodes_q.empty()) {
            int q_size = nodes_q.size();
            for (int i = 0; i < q_size; i++) {
                auto [node, col] = nodes_q.front();
                nodes_q.pop();

                columns[col].push_back(node->val);

                min_col = min(col, min_col);
                max_col = max(col, max_col);

                if (node->left) {
                    nodes_q.push({node->left, col - 1});
                }
                if (node->right) {
                    nodes_q.push({node->right, col + 1});
                }
            }
        }

        for (int col = min_col; col <= max_col; col++) {
            result.push_back(columns[col]);
        }
        
        return result;

    }
};