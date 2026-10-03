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
    unordered_map<int, ListNode *> cache_;

    int count_;
    int capacity_;

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

public:
    LRUCache(int capacity) {
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);

        head->next = tail;
        tail->prev = head;

        count_ = 0;
        capacity_ = capacity;
    }

    ~LRUCache() {
        ListNode *p = head->next;
        while (p) {
            ListNode *temp = p;
            p = p->next;
            delete temp;
        }

        delete head;
    }
    
    int get(int key) {
        if (count_ == 0) {
            return -1;
        }

        if (cache_.find(key) == cache_.end()) {
            return -1;
        }

        ListNode *node = cache_[key];
        remove(node);
        insert(node);

        return node->val;
    }
    
    void put(int key, int value) {
        // the key exists
        if (cache_.find(key) != cache_.end()) {
            ListNode *node = cache_[key];
            node->val = value;
            remove(node);
            insert(node);

            return;
        }
        
        // the key doesn't exist
        // check if the cache is full first before creating new node
        if (count_ == capacity_) {
            ListNode *lru = head->next;
            remove(lru);

            cache_.erase(lru->key);

            delete lru;
        }

        ListNode *node = new ListNode(key, value);
        insert(node);
        cache_[key] = node;
    }
};
