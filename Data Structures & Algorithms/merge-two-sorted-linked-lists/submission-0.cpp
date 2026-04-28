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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);

        ListNode *r = dummy;
        ListNode *p1 = list1;
        ListNode *p2 = list2;

        while (p1 && p2) {
            if (p1->val <= p2->val) {
                r->next = p1;
                p1 = p1->next;
                r = r->next;
            } else {
                r->next = p2;
                p2 = p2->next;
                r = r->next;
            }
        }

        if (p1) {
            r->next = p1;
        } else if (p2) {
            r->next = p2;
        }

        ListNode *head = dummy->next;
        delete dummy;

        return head;
    }
};
