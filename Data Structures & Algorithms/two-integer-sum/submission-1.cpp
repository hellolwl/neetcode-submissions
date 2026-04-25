class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, 0);
        std::unordered_map<int, int> num_map;

        for (int i = 0; i < nums.size(); i++) {
            if (num_map.count(target - nums[i])) {
                result[0] = num_map[target - nums[i]];
                result[1] = i;
                return result;
            } else {
                num_map[nums[i]] = i;
            }
        }
        
        return result;
    }
};
