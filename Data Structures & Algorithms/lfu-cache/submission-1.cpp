class LFUCache {
    struct ListNode {
        int key;
        int val;
        int freq;
        ListNode *prev;
        ListNode *next;

        ListNode(int k, int v) : key(k), val(v) {
            freq = 1;
            prev = nullptr;
            next = nullptr;
        }
    };

    struct LinkedList {
        ListNode *head;  // dummy node
        ListNode *tail;  // dummy node
        int size_;

        LinkedList() {
            head = new ListNode(0, 0);
            tail = new ListNode(0, 0);
            head->next = tail;
            tail->prev = head;
            size_ = 0;
        }

        ~LinkedList() {
            delete head;
            delete tail;
        }

        void pushToTail(ListNode *node) {
            ListNode *left = tail->prev;
            node->prev = left;
            node->next = tail;
            left->next = node;
            tail->prev = node;
            size_++;
        }

        void pop(ListNode *node) {
            ListNode *left = node->prev;
            ListNode *right = node->next;
            left->next = right;
            right->prev = left;
            node->prev = nullptr;
            node->next = nullptr;
            size_--;
        }

        ListNode *popFromHead() {
            ListNode *node = head->next;
            pop(node);
            return node;
        }

        int getSize() {
            return size_;
        }
        
    };

private:
    int capacity_;
    int min_freq_;
    unordered_map<int, ListNode*> node_map;
    unordered_map<int, LinkedList*> freq_map;
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
        min_freq_ = 0;
    }

    ~LFUCache() {
        for (auto & pair : node_map)
            delete pair.second;
        
        for (auto & pair : freq_map)
            delete pair.second;
    }

    void increaseFreq(ListNode *node) {
        int freq = node->freq;

        // step 1: Detach the node from the linked list of its old frequency
        freq_map[freq]->pop(node);

        // Step 2: Check whether need to increase the minimun frequency
        if (freq == min_freq_ && freq_map[freq]->getSize() == 0) {
            min_freq_++;
        }

        // Step 3: Bump the frequency
        node->freq++;

        // Step 4: Add the node to the linked list of new minimum frequency
        if (!freq_map.count(node->freq)) {
            freq_map[node->freq] = new LinkedList();
        }
        freq_map[node->freq]->pushToTail(node);
    }
    
    int get(int key) {
        if (!node_map.count(key)) {
            return -1;
        }

        ListNode *node = node_map[key];
        increaseFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        // zero capacity, just return
        if (capacity_ == 0) {
            return;
        }

        // the key alreay exists in the node_map, just increase the frequency and update the value
        if (node_map.count(key)) {
            ListNode *node = node_map[key];
            increaseFreq(node);
            node->val = value;
            return;
        }

        // the cache is already full, need to remove a element first
        if (node_map.size() == capacity_) {
            ListNode *node = freq_map[min_freq_]->popFromHead();
            node_map.erase(node->key);
            delete node;
        }

        ListNode *node = new ListNode(key, value);
        node_map[key] = node;
        // actually the node->freq is 1 here
        if (!freq_map.count(node->freq)) {
            freq_map[node->freq] = new LinkedList();
        }
        freq_map[node->freq]->pushToTail(node);
        min_freq_ = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */