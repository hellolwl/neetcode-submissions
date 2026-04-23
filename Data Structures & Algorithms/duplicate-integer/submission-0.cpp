class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> num_map;
        
        for (int x : nums) {
            if (!num_map.count(x)) {
                num_map[x]++;
            } else {
                return true;
            }
        }

        return false;
    }
};