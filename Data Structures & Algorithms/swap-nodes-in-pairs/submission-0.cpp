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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        while (prev->next) {
            ListNode *p1 = prev->next;
            if (p1->next) {
                ListNode *p2 = p1->next;
                ListNode *temp = p2->next;
                p2->next = p1;
                p1->next = temp;
                prev->next = p2;

                prev = prev->next->next;
            } else {
                break;
            }
        }
        
        return dummy.next;
    }
};
