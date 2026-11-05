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
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *group_leader = &dummy;
        while (group_leader && group_leader->next) {
            ListNode *p = group_leader->next;
            if (!p->next) { // the last - node
                group_leader->next = nullptr;
                break;
            }
            p = p->next;
            int sum = 0;
            while (p->val) {
                sum += p->val;
                p = p->next;
            }
            if (sum) {
                ListNode *node = new ListNode(sum);
                node->next = p;
                group_leader->next = node;
                group_leader = group_leader->next;
            }
        }

        return dummy.next;
    }
};
