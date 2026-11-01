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
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode *findMiddle(ListNode *head) {
        ListNode *slow = head;

        if (!head->next) return head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
public:
    int pairSum(ListNode* head) {
        ListNode *p1 = head;
        ListNode *p2 = findMiddle(head);
        int result = 0;
        p2 = reverseList(p2);
        while (p1 && p2) {
            result = max(result, p1->val + p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return result;
    }
};