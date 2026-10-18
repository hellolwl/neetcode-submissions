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
    ListNode* swapNodes(ListNode* head, int k) {
        int i = 0;
        ListNode *p1 = head;
        for (i = 0; i < k - 1; i++) {
            p1 = p1->next;
        }

        ListNode *tail = reverseList(head);
        ListNode *p2 = tail;
        for (i = 0; i < k - 1; i++) {
            p2 = p2->next;
        }

        int temp = p1->val;
        p1->val = p2->val;
        p2->val = temp;

        return reverseList(tail);
    }

};
