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
        if (head == nullptr || head->next == nullptr || left == right) {
            // no need to reverse
            return head;
        }

        ListNode dummy(0, head);
        ListNode *group_head = &dummy;
        int i = 0;
        for (i = 0; i < left - 1; i++) {
            group_head = group_head->next;
        }

        i = 0;
        ListNode *p = group_head->next;
        ListNode *q = p->next;
        while (q != nullptr && i < right - left) {
            p->next = q->next;
            q->next = group_head->next;
            group_head->next = q;
            q = p->next;
            i++;
        }

        return dummy.next;
    }
};