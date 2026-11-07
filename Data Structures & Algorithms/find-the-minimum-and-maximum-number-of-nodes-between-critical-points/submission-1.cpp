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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result(2, 0);
        result[0] = INT_MAX;
        result[1] = INT_MIN;
        ListNode *prev = head;
        ListNode *curr = prev->next;
        ListNode *next = curr->next;
        int first_critical_pos = -1;
        int last_critical_pos = -1;
        int i = 1;
        while (next) {
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                    if (first_critical_pos == -1) {
                        first_critical_pos = i;
                        last_critical_pos = i;
                    } else {
                        result[0] = std::min(result[0], i - last_critical_pos);
                        last_critical_pos = i;
                    }
            }
            prev = prev->next;
            curr = prev->next;
            if (curr) {
                next = curr->next;
            } else {
                break;
            }
            i++;
        }

        if (first_critical_pos == -1 || first_critical_pos == last_critical_pos) {
            result[0] = result[1] = -1;
        } else {
            result[1] = last_critical_pos - first_critical_pos;
        }
        
        return result;
    }
};
