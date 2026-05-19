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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);

        ListNode *p = dummy;
        ListNode *q = dummy;

        for (int i = 0; i < n; i++) {
            q = q->next;
        }

        while (q->next) {
            p = p->next;
            q = q->next;
        }
        
        ListNode *temp = p->next;
        p->next = temp->next;
        delete temp;

        return dummy->next;
    }
};
