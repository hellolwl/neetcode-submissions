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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_index_map[inorder[i]] = i;    
        }

        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    unordered_map<int, int> inorder_index_map;
    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end) {
            return nullptr;
        }

        int root_val = preorder[pre_start];
        int root_in_index = inorder_index_map[root_val];
        int left_size = root_in_index - in_start;

        TreeNode *root = new TreeNode(root_val);
        root->left = build(preorder, inorder, pre_start + 1, pre_start + left_size, in_start, root_in_index - 1);
        root->right = build(preorder, inorder, pre_start + left_size + 1, pre_end, root_in_index + 1, in_end);

        return root;
    }
};
