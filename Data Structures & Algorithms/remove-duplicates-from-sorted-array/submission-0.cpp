class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int temp = nums[0];
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != temp) {
                nums[k] = nums[i];
                temp = nums[k];
                k++;
            } 
        }

        return k;
    }
};