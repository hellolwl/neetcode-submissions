/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> pointer_map;
        Node *head2 = nullptr;
        
        Node *p = head;
        Node *q = head2;
        while (p) {
            if (!head2) {
                // create the first node of the new list
                head2 = new Node(p->val);
                q = head2;
                pointer_map[p] = q;
            } else {
                q->next = new Node(p->val);
                pointer_map[p] = q->next;
                q = q->next;
            }

            p = p->next;
        }

        p = head;
        q = head2;
        while (p) {
            if (p->random != nullptr) {
                q->random = pointer_map[p->random];
            } else {
                q->random = nullptr;
            }
            p = p->next;
            q = q->next;
        }

        return head2;
    }
};
