class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        for (i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }

        if (i > 0) {
            return strs[0].substr(0, i);
        } else {
            return "";
        }
    }
};