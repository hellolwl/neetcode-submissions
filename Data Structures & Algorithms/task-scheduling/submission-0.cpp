class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> count = {0};
        for (auto & t : tasks) {
            count[t - 'A']++;
        }

        priority_queue<int, vector<int>, less<int>> max_heap;
        for (auto & c : count) {
            if (c > 0) {
                max_heap.push(c);
            }
        }
        
        int time = 0;
        queue<pair<int, int>> cooldown;
        while (!max_heap.empty() || !cooldown.empty()) {
            time++;

            if (!cooldown.empty() && cooldown.front().first == time) {
                max_heap.push(cooldown.front().second);
                cooldown.pop();
            }

            if (!max_heap.empty()) {
                int freq = max_heap.top();
                max_heap.pop();

                if (freq - 1 > 0) {
                    cooldown.push({time + n + 1, freq - 1});
                }
            } else {
                // idle
            }
        }

        return time;
    }
};
