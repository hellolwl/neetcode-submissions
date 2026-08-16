class MyHashSet {
public:
    MyHashSet() : buckets_(bucket_size) {
        // TODO: implement
    }

    void add(int key) {
        int idx = getIndex(key);
        auto &bucket = buckets_[idx];
        auto it = bucket.begin();
        while (it != bucket.end()) {
            if (*it == key) {
                break;
            }
            it++;
        }

        // key doesn't exist, add it now
        if (it == bucket.end()) {
            bucket.push_back(key);
        }
    }

    void remove(int key) {
        int idx = getIndex(key);
        auto &bucket = buckets_[idx];
        auto it = bucket.begin();
        while (it != bucket.end()) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
            it++;
        }
    }

    bool contains(int key) {
        int idx = getIndex(key);
        auto &bucket = buckets_[idx];
        auto it = bucket.begin();
        while (it != bucket.end()) {
            if (*it == key) {
                return true;
            }
            it++;
        }
        return false;
    }

private:
    vector<list<int>> buckets_;
    static constexpr int bucket_size = 1009;

    int getIndex(int key) {
        return key % bucket_size;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */