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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) { return head; }

        ListNode *tail = head;
        int len = 1; // the first while loop will itereate len - 1 times
        int i = 0;
        while (tail->next) {
            len++;
            tail = tail->next;
        }

        if ((k = k % len)== 0) return head;

        ListNode *head1 = head;
        ListNode *tail1 = head1;
        for (i = 0; i < len - 1 - k; i++) {
            tail1 = tail1->next;
        }

        ListNode *head2 = tail1->next;
        tail->next = head1;
        tail1->next = nullptr;

        return head2;
    }
};