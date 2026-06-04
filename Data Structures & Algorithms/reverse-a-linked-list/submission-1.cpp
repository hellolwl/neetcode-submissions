/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0, head);
        ListNode *new_head = &dummy;
        ListNode *p = head;
        ListNode *q = p->next;

        while (q) {
            p->next = q->next;
            q->next = new_head->next;
            new_head->next = q;
            q = p->next;
        }
        
        return new_head->next;
    }
};
