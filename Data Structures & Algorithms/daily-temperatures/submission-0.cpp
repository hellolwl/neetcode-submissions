class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> index_s;
        vector<int> result(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            if (index_s.empty() || temperatures[i] < temperatures[index_s.top()]) {
                index_s.push(i);
            } else {
                while (!index_s.empty() && temperatures[i] > temperatures[index_s.top()]) {
                    int t = index_s.top();
                    result[t] = i - t;
                    index_s.pop();
                }
                index_s.push(i);
            }
        }

        return result;
    }
};
