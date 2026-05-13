class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int r = 0; r < nums.size(); r++) {
            while (!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(r);

            if ( dq.front() < r - k + 1) {
                dq.pop_front();
            }

            if (r >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};
