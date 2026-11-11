/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node *> st;
        vector<int> result;

        if (!root) return result;

        st.push(root);
        while(!st.empty()) {
            int count = st.size();
            for (int i = 0; i < count; i++) {
                Node *node = st.top();
                st.pop();
                result.push_back(node->val);

                for (int j = 0; j < node->children.size(); j++) {
                    st.push(node->children[j]);
                }
            }
        }
        
        reverse(result.begin(), result.end());

        return result;
    }
};