class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = left + k - 1;
        vector<int> result;

        while (right < nums.size()) {
            priority_queue<int> pq;
            for (int i = left; i <= right; i++) {
                pq.push(nums[i]);
            }
            result.push_back(pq.top());
            left++;
            right++;
        }
        
        return result;
    }
};
