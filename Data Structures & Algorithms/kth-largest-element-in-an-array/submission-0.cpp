class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> max_heap;

        for (auto & n : nums) {
            max_heap.push(n);

            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }

        return max_heap.top();
    }
};
