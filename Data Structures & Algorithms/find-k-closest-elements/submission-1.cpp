class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = static_cast<int>(arr.size()) - 1;

        while (r - l + 1 > k) {
            if (abs(arr[l] - x) > abs(arr[r] - x)) {
                l++;
            } else {
                r--;
            }
        }

        vector<int> res(arr.begin() + l, arr.begin() + r + 1);
        return res;
    }
};