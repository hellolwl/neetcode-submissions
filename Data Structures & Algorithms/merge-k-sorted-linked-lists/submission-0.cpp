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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (ListNode *l : lists) {
            pq.push(l);
        }

        ListNode dummy(0);
        ListNode *it = &dummy;
        while (!pq.empty()) {
            ListNode *curr = pq.top();
            pq.pop();
            it->next = curr;
            it = it->next;
            if (curr->next)
                pq.push(curr->next);
        }
        
        return dummy.next;
    }
};
