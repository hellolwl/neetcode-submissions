class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        unordered_map<int, int> count;
        int result = 0;

        for (int r = 0; r < static_cast<int>(fruits.size()); r++) {
            count[fruits[r]]++;

            while (count.size() > 2) {
                count[fruits[l]]--;
                if (count[fruits[l]] == 0) {
                    count.erase(fruits[l]);
                }
                l++;
            }

            result = max(result, r - l + 1);
        }
        
        return result;
    }
};