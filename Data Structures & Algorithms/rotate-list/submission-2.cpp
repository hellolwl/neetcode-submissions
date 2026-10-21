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
        if (!head || !head->next) return head;

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

    ListNode *concatLists(ListNode *head1, ListNode *head2) {
        if (!head1) return head2;
        if (!head2) return head1;

        ListNode *p = head1;
        while (p->next) {
            p = p->next;
        }
        p->next = head2;

        return head1;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        
        int list_len = 0;
        ListNode *p = head;
        while (p) {
            list_len++;
            p = p->next;
        }   
        k = k % list_len;
        if (k == 0) return head;

        ListNode *h1 = reverseList(head);
        p = h1;
        for (int i = 0; i < k - 1; i++) {
            p = p->next;
        }

        ListNode *h2 = p->next;
        p->next = nullptr;

        h1 = reverseList(h1);
        h2 = reverseList(h2);

        return concatLists(h1, h2);
    }
};