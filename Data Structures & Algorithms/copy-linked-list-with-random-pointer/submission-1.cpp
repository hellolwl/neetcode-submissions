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
        unordered_map<Node *, Node *> node_map;
        Node *head2 = nullptr;
        Node *p = nullptr;
        Node *q = nullptr;

        for (p = head; p; p = p->next) {
            if (!head2) {
                head2 = new Node(p->val);
                q = head2;
                node_map[p] = q;
            } else {
                Node *temp = new Node(p->val);
                q->next = temp;
                q = q->next;
                node_map[p] = temp;
            }
        }

        p = head;
        q = head2;
        while (p && q) {
            q->random = node_map[p->random];
            p = p->next;
            q = q->next;
        }
  
        return head2;      
    }
};
