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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *>  st;
        TreeNode* curr = root;
        TreeNode *prev;
        vector<int> result;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            TreeNode *node = st.top();
            if (node->right == nullptr || node->right == prev) {
                result.push_back(node->val);
                st.pop();
                prev = node;
            } else {
                curr = node->right;
            }
        }

        return result;
    }
};