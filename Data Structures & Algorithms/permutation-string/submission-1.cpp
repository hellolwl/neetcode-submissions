class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 > len2) {
            return false;
        }

        int l = 0;
        int r = 0;
        array<int, 26> need = {};
        array<int, 26> window = {};

        for (int c : s1) {
            need[c - 'a']++;
        }

        for (r = 0; r < static_cast<int>(len2); r++) {
            window[s2[r] - 'a']++;

            if (r - l + 1 > len1) {
                window[s2[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == len1 && window == need) {
                return true;
            }
        }

        return false;
    }
};
