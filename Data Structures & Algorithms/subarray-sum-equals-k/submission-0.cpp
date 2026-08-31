class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix_sum = 0;
        int count = 0;
        unordered_map<int, int> prefix_count;

        prefix_count[0] = 1;
        for (auto & num : nums) {
            prefix_sum += num;
            if (prefix_count.find(prefix_sum - k) != prefix_count.end()) {
                count += prefix_count[prefix_sum - k];
            }
            prefix_count[prefix_sum]++;
        }
        
        return count;
    }
};