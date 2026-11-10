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
        stack<ListNode *> st1;
        stack<ListNode *> st2;
        int carry = 0;
        ListNode dummy(0);
        ListNode *tail = &dummy;

        for (ListNode *p1 = l1; p1; p1 = p1->next) st1.push(p1);
        for (ListNode *p2 = l2; p2; p2 = p2->next) st2.push(p2);

        while (!st1.empty() || !st2.empty() || carry > 0) {
            int sum = 0;
            if (!st1.empty()) {
                sum += (st1.top())->val;
                st1.pop();
            }
            if (!st2.empty()) {
                sum += (st2.top())->val;
                st2.pop();
            }
            if (carry > 0) {
                sum += carry;
            }

            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }

            ListNode *node = new ListNode(sum);
            node->next = dummy.next;
            dummy.next = node;
        }

        return dummy.next;
        
    }
};