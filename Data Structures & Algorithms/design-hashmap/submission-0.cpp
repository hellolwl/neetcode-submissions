class MyHashMap {
public:
    MyHashMap() : buckets_(bucket_size) {

    }

    void put(int key, int value) {
        int idx = getIndex(key);
        auto &bucket = buckets_[idx];
        auto it = bucket.begin();

        while (it != bucket.end()) {
            if (it->first == key) {
                it->second = value;
                break;
            }
            it++;
        }

        if (it == bucket.end()) {
            bucket.push_back({key, value});
        }
    }

    int get(int key) {
        int idx = getIndex(key);
        auto &bucket = buckets_[idx];
        auto it = bucket.begin();

        while (it != bucket.end()) {
            if (it->first == key) {
                return it->second;
            }
            it++;
        }

        return -1;
    }

    void remove(int key) {
        int idx = getIndex(key);
        auto &bucket = buckets_[idx];
        auto it = bucket.begin();
        
        while (it != bucket.end()) {
            if (it->first == key) {
                bucket.erase(it);
                break;
            }
            it++;
        }
    }

private:
    vector<list<pair<int, int>>> buckets_;
    static constexpr int bucket_size = 1009;

    int getIndex(int key) {
        return key % bucket_size;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */