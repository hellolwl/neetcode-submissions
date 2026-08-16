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
        ListNode *p = head;
        ListNode *q = head->next;
        while (q) {
            p->next = q->next;
            q->next = dummy.next;
            dummy.next = q;
            q = p->next;
        }

        return dummy.next;
    }       
};
