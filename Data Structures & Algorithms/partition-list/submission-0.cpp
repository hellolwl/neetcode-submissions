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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode l_head;
        ListNode *l_tail = &l_head;
        // ListNode *target = nullptr;
        ListNode r_head;
        ListNode *r_tail = &r_head;

        for (ListNode *p = head; p; p = p->next) {
            if (p->val < x) {
                // insert the node to left list
                l_tail->next = p;
                l_tail = l_tail->next;
            } else {
                // insert the node to the right list
                r_tail->next = p;
                r_tail = r_tail->next;
            }
        }

        r_tail->next = nullptr;
        l_tail->next = r_head.next;

        return l_head.next;
    }
};
