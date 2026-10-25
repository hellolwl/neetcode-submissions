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
private:
    void insert(ListNode *head, ListNode *node) {
        bool inserted = false;

        ListNode *prev = head;
        while (prev->next) {
            if (prev->val <= node->val && node->val <= prev->next->val) {
                ListNode *temp = prev->next;
                prev->next = node;
                node->next = temp;    
                inserted = true;
                return;  
            }
            prev = prev->next;
        }

        if (prev->next == nullptr && inserted == false) {
            prev->next = node;
        }
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN);

        ListNode *p = head;
        while (p) {
            ListNode *curr = p;
            p = p->next;
            curr->next = nullptr; // detach the node from original list
            insert(&dummy, curr);
        }

        return dummy.next;
    }
};