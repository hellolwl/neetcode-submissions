class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = static_cast<int>(heights.size() - 1);
        int max_area = 0;

        while (left < right) {
            max_area = max(max_area, min(heights[right], heights[left]) * (right - left));
            if (heights[left] <= heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
