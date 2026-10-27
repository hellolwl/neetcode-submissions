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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> count;
        for (ListNode *p = head; p; p = p->next) {
            count[p->val]++;
        }

        ListNode dummy(0, head);
        ListNode *prev = &dummy;

        while (prev->next) {
            ListNode *curr = prev->next;
            if (count[curr->val] > 1) {
                prev->next = curr->next;
                delete curr;
            } else {
                prev = prev->next;
            }
        }

        return dummy.next;
    }
};
