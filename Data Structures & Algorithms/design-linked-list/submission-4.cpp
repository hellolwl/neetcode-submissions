struct ListNode {
    int val;
    ListNode *prev;
    ListNode *next;

    ListNode(int v) : val(v) {
        prev = nullptr;
        next = nullptr;
    }
};

class MyLinkedList {
private:
    ListNode *head;
    ListNode *tail;
    int count;
public:
    MyLinkedList() {
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
        count = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= count) {
            return -1;
        }
        ListNode *curr = head->next;
        for (int i = 1; i <= index; i++) {
            curr = curr->next;
        }
        
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        count++;
    }
    
    void addAtTail(int val) {
        ListNode *node = new ListNode(val);
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        count++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > count) {
            return;
        }
        ListNode *curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        ListNode *node = new ListNode(val);
        node->next = curr->next;
        node->prev = curr;
        curr->next->prev = node;
        curr->next = node;

        count++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= count) {
            return;
        }
        ListNode *prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        ListNode *temp = prev->next;
        prev->next = temp->next;
        temp->next->prev = prev;

        delete temp;

        count--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */