class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data_store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (data_store.find(key) == data_store.end()) {
            return "";
        }

        auto &vec = data_store[key];
        int lo = 0;
        int hi = vec.size() - 1;
        int res = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (vec[mid].first <= timestamp) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return res == -1 ? "" : vec[res].second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> data_store;
};
