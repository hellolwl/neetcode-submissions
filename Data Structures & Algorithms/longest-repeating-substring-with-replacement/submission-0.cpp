class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int max_len = 0;
        int max_freq = 0;


        unordered_map<char, int> char_map;
        for (int r = 0; r < s.length(); r++) {
            char_map[s[r]]++;
            max_freq = max(max_freq, char_map[s[r]]);

            while ((r - l + 1) - max_freq > k) {
                char_map[s[l]]--;
                if (char_map[s[l]] == 0) {
                    char_map.erase(s[l]);
                }
                l++;
            }

            max_len = max(max_len, r - l + 1);
        }

        return max_len;
        
    }
};
