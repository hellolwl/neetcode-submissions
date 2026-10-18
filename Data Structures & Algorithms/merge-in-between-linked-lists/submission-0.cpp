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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode dummy(0, list1);
        ListNode *group_head = &dummy;
        int i = 0;

        for (i = 0; i < a; i++) {
            group_head = group_head->next;
        }

        ListNode *group_tail = group_head->next;
        for (i = 0; i < (b - a); i++)  {
            group_tail = group_tail->next;
        }

        group_head->next = list2;
        ListNode *list2_tail = list2;
        while (list2_tail->next) {
            list2_tail = list2_tail->next;
        }

        list2_tail->next = group_tail->next;

        return dummy.next;
    }
};
