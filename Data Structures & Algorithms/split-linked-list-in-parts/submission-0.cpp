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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *group_head = head;
        int group_count; // how many nodes does a group have
        int num_of_groups = 0;
        int remaining_count = 0; // how many nodes need to be splited
        ListNode *p = head;
        vector<ListNode *> result;

        while (p) {
            remaining_count++;
            p = p->next;
        }

        while (remaining_count) {
            if (remaining_count > (k - num_of_groups)) {
                group_count = remaining_count / (k - num_of_groups) + ( remaining_count % (k - num_of_groups) == 0 ? 0 : 1);
            } else {
                group_count = 1;
            }

            ListNode *group_tail = group_head;
            for (int i = 0; i < group_count - 1; i++) {
                group_tail = group_tail->next;
            }
            result.push_back(group_head);
            group_head = group_tail->next;
            group_tail->next = nullptr;

            remaining_count -= group_count;
            num_of_groups++;
        }

        while (num_of_groups < k) {
            result.push_back(nullptr); // fill the result with nullptr
            num_of_groups++;
        }

        return result;
    }
};
