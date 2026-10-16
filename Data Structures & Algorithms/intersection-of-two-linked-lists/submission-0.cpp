/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        unordered_set<ListNode *> nodes_set;
        while (p1) {
            nodes_set.insert(p1);
            p1 = p1->next;
        }

        while (p2) {
            if (nodes_set.find(p2) != nodes_set.end()) {
                return p2;
            }
            p2 = p2->next;
        }

        return nullptr;
    }
};