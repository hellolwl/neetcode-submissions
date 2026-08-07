class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        auto cmp = [](vector<int> & p1, vector<int> & p2) {
            return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> min_heap_(cmp);

        // int i = 0;
        for (auto & pt : points) {
            min_heap_.push(pt);

            if (min_heap_.size() > k) {
                min_heap_.pop();
            }
        }

        while (min_heap_.size() > 0) {
            auto pt = min_heap_.top(); min_heap_.pop();
            result.push_back(pt);
        }

        return result;
    }
};