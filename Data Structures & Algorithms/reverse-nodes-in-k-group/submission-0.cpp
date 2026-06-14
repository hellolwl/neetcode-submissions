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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0, head);
        ListNode *group_head = &dummy;

        while (group_head != nullptr) {
            int i = 0;
            ListNode *p = group_head;
            for (i = 0; i < k && p != nullptr; i++) {
                p = p->next;
            }

            // The node count in this group is less than k
            if (i < k || p == nullptr) break;

            // reverse this group
            i = 0;
            p = group_head->next;
            ListNode *q = p->next;
            while (i < k - 1) {
                p->next = q->next;
                q->next = group_head->next;
                group_head->next = q;
                q = p->next;
                i++;
            }

            if (p != nullptr) {
                group_head = p;
            }
        }

        return dummy.next;
    }
};
