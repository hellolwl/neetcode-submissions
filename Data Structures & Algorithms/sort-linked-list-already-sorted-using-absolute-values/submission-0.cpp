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

    ListNode *mergeSortedList(ListNode *head1, ListNode *head2) {
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                tail->next = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }

        if (p1) {
            tail->next = p1;
        } else if (p2) {
            tail->next = p2;
        }

        return dummy.next;
    }
public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode dummy_pos(INT_MIN, head); // the List that only has 0 and postive values
        ListNode dummy_neg(INT_MIN);       // the List that only has negative values
        ListNode *tail_neg = &dummy_neg;
        ListNode *p = &dummy_pos;
        while (p->next) {
            if (p->next->val < 0) {
                // remove the node from the postive list
                ListNode *temp = p->next;
                p->next = temp->next;
                temp->next = nullptr;

                // insert the node to the negative list
                tail_neg->next = temp;
                tail_neg = tail_neg->next;
            } else {
                p = p->next;
            }
        }

        ListNode *head1 = dummy_pos.next;
        ListNode *head2 = reverseList(dummy_neg.next);
        return mergeSortedList(head1, head2);
    }
};
