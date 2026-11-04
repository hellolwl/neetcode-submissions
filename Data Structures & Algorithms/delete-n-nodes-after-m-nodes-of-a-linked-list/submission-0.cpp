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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode dummy(0, head);
        ListNode *p = &dummy;
        ListNode *q = nullptr;
        while (p && p->next) {
            int i = 0;
            for (i = 0; p && i < m; i++) {
                p = p->next;
            }
            if (!p) {
                break;
            }
            q = p;
            for (i = 0; q && i < n; i++) {
                q = q->next;
            }
            p->next = q ? q->next : nullptr;
        }
        
        return dummy.next;
    }
};