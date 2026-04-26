class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<int>> sorted_map;
        vector<vector<string>> result;

        for (int i = 0; i < strs.size(); i++) {
            // don't change the original string in strs
            string sorted_str = strs[i];
            std::sort(sorted_str.begin(), sorted_str.end());

            sorted_map[sorted_str].push_back(i);
        }

        for (const auto& [key, values] : sorted_map) {
            vector<string> subset;
            for (int val : values) {
                subset.push_back(strs[val]);
            }
            result.push_back(subset);
        }

        return result;
    }
};
