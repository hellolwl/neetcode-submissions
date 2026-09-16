struct ListNode {
    int key;
    int val;
    ListNode *prev;
    ListNode *next;

    ListNode(int k, int v) : key(k), val(v) {
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    ListNode *head;
    ListNode *tail;
    unordered_map<int, ListNode *> node_map;
    int capacity_;
    int count_;

    void insert(ListNode *node) {
        ListNode *prev = tail->prev;
        node->prev = prev;
        node->next = tail;
        prev->next = node;
        tail->prev = node;
        count_++;
    }

    void remove(ListNode *node) {
        ListNode *prev = node->prev;
        ListNode *next = node->next;
        prev->next = next;
        next->prev = prev;
        count_--;
    }

    ListNode * pop() {
        ListNode *node = head->next;
        head->next = node->next;
        node->next->prev = head;
        count_--;
        return node;
    }


public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        count_ = 0;
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        ListNode *p = head;
        while (p) {
            ListNode *tmp = p;
            p = p->next;
            delete tmp;
        }
    }
    
    int get(int key) {
        if (node_map.find(key) == node_map.end()) {
            return -1;
        }

        ListNode *node = node_map[key];
        remove(node);
        insert(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (node_map.find(key) != node_map.end()) {
            ListNode *node = node_map[key];
            node->val = value;
            remove(node);
            insert(node);
            
            return;
        }

        if (count_ == capacity_) {
            ListNode *lru = pop();
            node_map.erase(lru->key);
        }

        ListNode *node = new ListNode(key, value);
        node_map[key] = node;
        insert(node);
    }
};
