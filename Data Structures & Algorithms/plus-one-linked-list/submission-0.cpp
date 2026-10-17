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
private:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *tail = reverseList(head);

        ListNode *p = tail;
        int carry = 0;
        while (p) {
            int sum = 0;
 
            if (p == tail) { // first node
                sum = 1 + carry + p->val; // carry is 0
            } else {
                sum = carry + p->val;
            }
            if (sum == 10) {
                carry = 1;
                p->val = 0;

                if (p->next != nullptr) {
                    p = p->next;
                } else {
                    ListNode *temp = new ListNode(1);
                    p->next = temp;
                    p = p->next;
                    break;
                }
            } else {
                p->val = sum;
                break;
            }
        }

        return reverseList(tail);
    }
};
