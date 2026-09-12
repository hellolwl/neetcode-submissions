struct ListNode {
    int val;
    ListNode *prev;
    ListNode *next;

    ListNode(int v) : val(v) {
        prev = nullptr;
        next = nullptr;
    }
};

class MyCircularQueue {
private:
    int capacity_;
    int count_;
    ListNode *head;
    ListNode *tail;

public:
    MyCircularQueue(int k) {
        capacity_ = k;
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
        count_ = 0;
    }
    
    bool enQueue(int value) {
        if (count_ == capacity_) {
            return false;
        }

        ListNode *node = new ListNode(value);
        ListNode *prev = tail->prev;
        node->prev = prev;
        node->next = tail;
        prev->next = node;
        tail->prev = node;
        count_++;

        return true;
    }
    
    bool deQueue() {
        if (count_ == 0) {
            return false;
        }

        ListNode *node = head->next;
        head->next = node->next;
        node->next->prev = head;
        delete node;
        count_--;

        return true;
    }
    
    int Front() {
         if (count_ == 0) {
            return -1;
        }

        return head->next->val;
    }
    
    int Rear() {
        if (count_ == 0) {
            return -1;
        }

        return tail->prev->val;
    }
    
    bool isEmpty() {
        return head->next == tail;
    }
    
    bool isFull() {
        return count_ == capacity_;
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