class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int start = 0;
        int best_len = INT_MAX;
        int have = 0;
        unordered_map<char, int> need_map;
        unordered_map<char, int> window_map;

        for (char c : t) {
            need_map[c]++;
        }

        while (right < s.length()) {
            char in = s[right];
            window_map[in]++;
            right++;

            if (need_map.count(in)) {
                if (window_map[in] == need_map[in]) {
                    have++;
                }
            }

            // condition satisfied, continue to look for the best len
            while (have == need_map.size()) {
                if (right - left < best_len) {
                    best_len = right - left;
                    start = left;
                }

                // move the character out from the window
                char out = s[left];
                left++;

                if (need_map.count(out)) {
                    if (window_map[out] == need_map[out]) {
                        have--;
                    }
                }
                window_map[out]--;
            }
        }

        return best_len == INT_MAX ? "" : s.substr(start, best_len);
    }
};
