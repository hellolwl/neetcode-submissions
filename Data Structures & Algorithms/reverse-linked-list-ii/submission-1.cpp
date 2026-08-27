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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        int i = 0;
        int count = right - left;

        if (count == 0) {
            // no need to reverse
            return head;
        }

        ListNode *group_head = &dummy;
        for (i = 0; i < left - 1; i++) {
            group_head = group_head->next;
        }

        ListNode *p = group_head->next;
        ListNode *q = p->next;
        i = 0;
        while (i < count) {
            p->next = q->next;
            q->next = group_head->next;
            group_head->next = q;
            q = p->next;
            i++;
        }

        return dummy.next;      
    }
};