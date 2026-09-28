class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int window_sum = 0;
        int min_len = INT_MAX;

        for (int r = 0; r < static_cast<int>(nums.size()); r++) {
            window_sum += nums[r];

            while (window_sum >= target) {
                min_len = min(min_len, r - l + 1);
                window_sum -= nums[l];
                l++;   
            }
        }

        return min_len == INT_MAX ? 0 : min_len;
    }
};