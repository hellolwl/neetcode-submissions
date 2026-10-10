/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *node = new Node(insertVal);
        if (!head) {
            node->next = node;
            return node;
        }

        Node *prev = head;
        while (true) {
            if (prev->val <= insertVal && insertVal <= prev->next->val) {
                break;
            } else if (prev->val > prev->next->val) {
                if (insertVal >= prev->val || insertVal <= prev->next->val) {
                    break;
                }
            }
            if (prev->next == head) {
                break;
            }
            prev = prev->next;
        }

        node->next = prev->next;
        prev->next = node;
        return head;
    }
};
