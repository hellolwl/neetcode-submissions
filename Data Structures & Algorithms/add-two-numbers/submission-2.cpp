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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode dummy(0);
        ListNode *tail = &dummy;
        int carry = 0;

        while (p1 || p2 || carry > 0) {
            int v1 = p1 ? p1->val : 0;
            int v2 = p2 ? p2->val : 0;
            int sum = v1 + v2 + carry;
            int val = sum % 10;
            carry = sum / 10;

            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;

            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy.next;     
    }
};
