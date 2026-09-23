class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int n = static_cast<int>(arr.size());
        int r = n - 1;

        while (r - l + 1 > k) {
            if (abs(arr[l] - x) > abs(arr[r] - x)) {
                l++;
            } else {
                r--;
            }
        }

        vector<int> res(arr.begin() + l, arr.begin() + l + k);
        return res;
    }
};