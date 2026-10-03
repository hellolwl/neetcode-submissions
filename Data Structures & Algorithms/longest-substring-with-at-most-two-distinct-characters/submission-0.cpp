class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0;
        unordered_map<char, int> count;
        int max_len = 0;

        for (int r = 0; r < s.length(); r++) {
            count[s[r]]++;

            while (count.size() > 2) {
                count[s[l]]--;

                if (count[s[l]] == 0) {
                    count.erase(s[l]);
                }
                l++;
            }

            max_len = max(max_len, r - l + 1);
        }        

        return max_len;
    }
};