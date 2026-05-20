class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> s;
        int num = position.size();

        vector<pair<int, int>> cars(num);
        for (int i = 0; i < num; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        for (int i = 0; i < num; i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (s.empty() || time > s.top()) {
                s.push(time);
            }
        }

        return s.size();
    }
};