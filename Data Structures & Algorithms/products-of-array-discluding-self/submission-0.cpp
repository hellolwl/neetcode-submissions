class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        vector<int> result(nums.size(), 1);

        int i = 0;
        for (i = 0; i < nums.size(); i++) {
            if (i == 0) {
                left[i] = 1;
            } else {
                left[i] = nums[i - 1] * left[i - 1];
            }
        }

        for (i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                right[i] = 1;
            } else {
                right[i] = right[i + 1] * nums[i + 1];
            }
        }

        for (i = 0; i < nums.size(); i++) {
            result[i] = left[i] * right[i];
        }

        return result;
    }
};
