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
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        ListNode *tail = prev;

        // create a gap with size n
        for (int i = 0; i < n; i++) {
            tail = tail->next;
        }

        while (tail->next) {
            prev = prev->next;
            tail = tail->next;
        }

        ListNode *temp = prev->next;
        prev->next = temp->next;
        delete temp;

        return dummy.next;       
    }
};
