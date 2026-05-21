class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        heights.push_back(0);
        int num = heights.size();

        for (int i = 0; i < num; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                max_area = max(max_area, heights[mid] * width);
            }
            st.push(i);
        }

        heights.pop_back();
        return max_area;
    }
};
