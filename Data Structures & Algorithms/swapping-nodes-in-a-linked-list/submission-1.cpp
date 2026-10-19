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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *temp = head;
        int i = 0;
        for (i = 0; i < k - 1; i++) {
            p1 = p1->next;
            temp = temp->next;
        }

        while (temp->next) {
            p2 = p2->next;
            temp = temp->next;
        }

        swap(p1->val, p2->val);

        return head;
    }
};
