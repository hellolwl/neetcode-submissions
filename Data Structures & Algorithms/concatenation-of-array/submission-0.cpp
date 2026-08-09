class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;

        for (int i = 0; i < size * 2; i++) {
            result.push_back(nums[i % size]);
        }
        
        return result;
    }
};