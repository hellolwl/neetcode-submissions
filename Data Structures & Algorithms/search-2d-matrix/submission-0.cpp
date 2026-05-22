class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int num_of_row = matrix.size();
        bool found = false;

        for (int i = 0; i < num_of_row; i++) {
            found = binarySearch(matrix[i], target);
            if (found) {
                return true;
            }
        }

        return found;
    }

private:
    bool binarySearch(vector<int> arr, int target) {
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return false;
    }
};
