class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find the pivot first
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int mid  = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        int pivot = lo;
        // binary search left part
        int result = binarySearch(nums, target, 0, pivot - 1);
        if (result == -1) {
            // binary search right part if the result is not found in left part
            result = binarySearch(nums, target, pivot, nums.size() - 1);
        }

        return result;
    }

private:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        int lo = left;
        int hi = right;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return -1;
    }
};
