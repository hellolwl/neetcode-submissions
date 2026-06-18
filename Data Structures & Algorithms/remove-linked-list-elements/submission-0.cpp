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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        ListNode *curr = prev->next;

        while (curr) {
            if (curr->val == val) {
                ListNode *tmp = prev->next;
                prev->next = curr->next;
                delete tmp;
            } else {
                prev = prev->next;
            }
            curr = prev->next;
        }

        return dummy.next;
    }
};