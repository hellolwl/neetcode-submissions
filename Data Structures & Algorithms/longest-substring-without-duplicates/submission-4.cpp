class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_set<char> window;
        int max_len = INT_MIN;

        if (s.empty()) {
            return 0;
        }

        for (int r = 0; r < static_cast<int>(s.length()); r++) {
            while (window.count(s[r])) {
                window.erase(s[l]);
                l++;
            }

            window.insert(s[r]);
            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};
