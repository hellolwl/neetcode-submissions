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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *curr = root;
        vector<int> result;
        
        while (curr || !st.empty()) {
            while (curr) {
                result.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }

            TreeNode *node = st.top();
            st.pop();
            curr = node->right;
        }

        return result;
    }
};