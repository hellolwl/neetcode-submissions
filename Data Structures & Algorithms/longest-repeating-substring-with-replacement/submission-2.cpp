class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        array<int, 26> count = {0};
        int max_freq = 0;
        int max_len = 0;

        for (r = 0; r < s.length(); r++) {
            count[s[r] - 'A']++;
            max_freq = max(max_freq, count[s[r] - 'A']);
            while ((r - l + 1) - max_freq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};