class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        int n_row = matrix.size();
        int n_col = matrix[0].size();
        int hi = n_row * n_col - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / n_col][mid % n_col] == target) {
                return true;
            } else if (matrix[mid / n_col][mid % n_col] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return false;
    }
};
