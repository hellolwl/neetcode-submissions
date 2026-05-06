class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int h = min(heights[left], heights[right]);
            int w = right - left;

            result = max(h * w, result);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return result;
    }
};
