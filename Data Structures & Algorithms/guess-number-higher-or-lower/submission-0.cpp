/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        int res = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int g = guess(mid);
            if (g == 0) {
                res = mid;
                return res;
            } else if (g < 0) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};