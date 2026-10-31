/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        ImmutableListNode *p = head;
        stack<ImmutableListNode *> st;
        while (p) {
            st.push(p);
            p = p->getNext();
        }

        while (!st.empty()) {
            p = st.top();
            st.pop();
            p->printValue();
        }
    }
};
