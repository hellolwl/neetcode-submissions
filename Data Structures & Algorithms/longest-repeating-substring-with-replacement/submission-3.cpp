class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int max_freq = INT_MIN;
        array<int, 26> char_count = {};
        int res = 0;

        for (int r = 0; r < static_cast<int>(s.length()); r++) {
            char_count[s[r] - 'A']++;

            max_freq = max(max_freq, char_count[s[r] - 'A']);

            while (r - l + 1 - max_freq > k) {
                char_count[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
