class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        unordered_set<int> window;

        for (int r = 0; r < static_cast<int>(nums.size()); r++) {
            if (window.count(nums[r])) {
                return true;
            }

            window.insert(nums[r]);

            if (window.size() > k) {
                window.erase(nums[l]);
                l++;
            }
        }

        return false;
    }
};