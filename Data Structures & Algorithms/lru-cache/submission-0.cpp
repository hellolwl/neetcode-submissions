struct Node {
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node *left;
    Node *right;

    void remove(Node *node) {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node *node) {
        Node *prev = right->prev;
        node->prev = prev;
        node->next = right;
        prev->next = node;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node *node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node *old = cache[key];
            remove(cache[key]);
            delete old;
        }

        Node *node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if (cache.size() > cap) {
            Node *lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
