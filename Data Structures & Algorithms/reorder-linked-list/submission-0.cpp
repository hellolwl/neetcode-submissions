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
    void reorderList(ListNode* head) {
        ListNode *mid = findMiddle(head);
        ListNode *head2 = mid->next;
        mid->next = nullptr;
        head2 = reverseList(head2);

        head = mergeList(head, head2);
    }

private:
    ListNode *findMiddle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *current = head;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    ListNode *mergeList(ListNode *head1, ListNode *head2) {
        ListNode *first = head1;
        ListNode *second = head2;

        while (first && second) {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }

        return head1;
    }
};
