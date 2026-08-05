class Solution {
private:
    priority_queue<int, vector<int>, less<int>> max_heap_;

public:
    int lastStoneWeight(vector<int>& stones) {
        for (auto & s : stones) {
            max_heap_.push(s);
        }

        while (max_heap_.size() >= 2) {
            int x = max_heap_.top(); max_heap_.pop();
            int y = max_heap_.top(); max_heap_.pop();

            if (x != y) {
                max_heap_.push(abs(x - y));
            }
        }

        if (max_heap_.size() == 0) {
            return 0;
        } else {
            return max_heap_.top();
        }
    }
};
