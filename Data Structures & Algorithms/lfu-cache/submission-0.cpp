class LFUCache {
    struct ListNode {
        int key;
        int val;
        int freq;
        ListNode *prev;
        ListNode *next;

        ListNode(int k, int v) {
            key = k;
            val = v;
            freq = 1; // default frequency is 1
            prev = nullptr;
            next = nullptr;
        }
    };

    struct LinkedList {
        ListNode *left;
        ListNode *right;
        int size_;

        LinkedList() {
            left = new ListNode(0, 0);
            right = new ListNode(0, 0);
            left->next = right;
            right->prev = left;
            size_ = 0;
        }

        ~LinkedList() {
            delete left;
            delete right;
        }

        int length() {
            return size_;
        }

        void pushRight(ListNode *node) {
            ListNode *prev = right->prev;
            node->prev = prev;
            node->next = right;
            prev->next = node;
            right->prev = node;
            size_++;
        }

        void pop(ListNode *node) {
            ListNode *prev = node->prev;
            ListNode *next = node->next;
            prev->next = next;
            next->prev = prev;
            node->prev = nullptr;
            node->next = nullptr;
            size_--;
        }

        ListNode* popLeft() {
            ListNode *node = left->next;
            pop(node);
            return node;
        }
    };

private:
    int capacity_;
    int lfu_count_; // current minimum frequency
    unordered_map<int, ListNode*> node_map;
    unordered_map<int, LinkedList*> list_map;

    void touch(ListNode *node) {
        int count = node->freq;

        // Detach the node from the linked list of its old frequency
        list_map[count]->pop(node);

        // If this node was in the current minimum-frequency list,
        // and that list is now empty, the minimum frequency needs to move up by one.
        if (count == lfu_count_ && list_map[count]->length() == 0) {
            lfu_count_++;
        }

        // Bump the frequency 
        node->freq++;

        // Create the linked list for the new frequency if it doesn't exist yet
        if (!list_map.count(node->freq)) {
            list_map[node->freq] = new LinkedList();
        }

        // Add the node to the right end of the new frequency list.
        // The right end represents the most recently used position within the same frequency.
        list_map[node->freq]->pushRight(node);
    }
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
        lfu_count_ = 0;
    }

    ~LFUCache() {
        for (auto & pair : node_map) {
            delete pair.second;
        }

        for (auto & pair : list_map) {
            delete pair.second;
        }
    }
    
    int get(int key) {
        if (!node_map.count(key)) {
            return -1;
        }

        ListNode *node = node_map[key];
        touch(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (capacity_ == 0) {
            return;
        }

        if (node_map.count(key)) {
            ListNode *node = node_map[key];
            node->val = value;
            touch(node);
            return;
        }

        if (node_map.size() == capacity_) {
            ListNode *node = list_map[lfu_count_]->popLeft();
            node_map.erase(node->key);
            delete node;
        }
        
        ListNode *node = new ListNode(key, value);
        node_map[key] = node;
        if (!list_map.count(1)) {
            list_map[1] = new LinkedList();
        }
        list_map[1]->pushRight(node);
        lfu_count_ = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */