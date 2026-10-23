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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> num_set(nums.begin(), nums.end());

        ListNode dummy(0, head);
        ListNode *p = &dummy;

        while (p->next) {
            if (num_set.find(p->next->val) != num_set.end()) {
                ListNode *curr = p->next;
                cout << curr->val << endl;
                p->next = curr->next;
                delete curr;
            } else {
                p = p->next;
            }
        }

        return dummy.next;
    }
};
