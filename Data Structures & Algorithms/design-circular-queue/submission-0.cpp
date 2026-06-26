class MyCircularQueue {
private:
    struct ListNode {
        int val;
        ListNode *prev;
        ListNode *next;
        ListNode(int v) {
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    int space;
    ListNode *left;
    ListNode *right;
public:
    MyCircularQueue(int k) {
        space = k;
        left = new ListNode(0);
        right = new ListNode(0);
        left->next = right;
        right->prev = left;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        ListNode *curr = new ListNode(value);
        curr->prev = right->prev;
        curr->next = right;
        right->prev->next = curr;
        right->prev = curr;
        space--;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        ListNode *curr = left->next;
        left->next = curr->next;
        curr->next->prev = left;
        delete curr;
        space++;

        return true;
    }
    
    int Front() {
        return isEmpty() ? - 1: left->next->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : right->prev->val;
    }
    
    bool isEmpty() {
        return left->next == right;
    }
    
    bool isFull() {
        return space == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */