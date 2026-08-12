class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        
        for (auto & n : nums) {
            if (n != val) {
                nums[i++] = n;
            }
        }

        return i;
    }
};