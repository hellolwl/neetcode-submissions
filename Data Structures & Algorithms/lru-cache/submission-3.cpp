// Doubly linked list node
struct Node {
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int k, int v) : key(k), val(v) {
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int cap_;
    unordered_map<int, Node *> cache_;
    Node *left_;
    Node *right_;

public:
    LRUCache(int capacity) {
        cap_ = capacity;
        left_ = new Node(0, 0);
        right_ = new Node(0, 0);
        left_->next = right_;
        right_->prev = left_;
    }

    ~LRUCache() {
        Node *curr = left_;
        while (curr) {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void remove(Node *node) {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node *node) {
        Node *prev = right_->prev;
        node->prev = prev;
        node->next = right_;
        prev->next = node;
        right_->prev = node;
    }

    int get(int key) {
        auto it = cache_.find(key);
        if (it == cache_.end()) {
            return -1;
        }
        
        Node *node = it->second;
        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            Node *node = it->second;
            node->val = value;
            remove(node);
            insert(node);
            return;
        }

        Node *node = new Node(key, value);
        cache_[key] = node;
        insert(node);

        if (cache_.size() > static_cast<size_t>(cap_)) {
            Node *lru = left_->next;
            remove(lru);
            cache_.erase(lru->key);
            delete(lru);
        }
    }
};