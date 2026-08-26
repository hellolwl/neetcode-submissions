class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int n1 = nums[0];
        int n2 = nums[slow];
        while (n1 != n2) {
            n1 = nums[n1];
            n2 = nums[n2];
        }

        return n1;
    }
};
