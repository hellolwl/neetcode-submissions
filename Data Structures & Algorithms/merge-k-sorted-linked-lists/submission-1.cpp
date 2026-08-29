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
        auto cmp = [](ListNode *l1, ListNode *l2) {
            return l1->val > l2->val;
        };
        priority_queue<ListNode *, vector<ListNode*>, decltype(cmp)> min_heap(cmp);

        ListNode dummy(0);
        ListNode *tail = &dummy;

        if (lists.empty()) {
            return nullptr;
        }

        for (auto & head : lists) {
            if (head) min_heap.push(head);
        }

        while (!min_heap.empty()) {
            ListNode *temp = min_heap.top();
            min_heap.pop();
            if (temp->next)
                min_heap.push(temp->next);
            tail->next = temp;
            tail = tail->next;
        }

        return dummy.next;       
    }
};
