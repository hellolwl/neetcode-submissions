class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int res = 0;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};