class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        capacity_ = k;
        for (auto n : nums) {
            add(n);
        }
        
    }
    
    int add(int val) {
        min_heap_.push(val);

        if (min_heap_.size() > static_cast<size_t>(capacity_)) {
            min_heap_.pop();
        }

        return min_heap_.top();
        
    }

private:
    int capacity_;
    priority_queue<int, vector<int>, greater<int>> min_heap_;
};
