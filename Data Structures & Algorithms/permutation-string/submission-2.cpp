class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        array<int, 26> need = {};
        array<int, 26> window = {};

        for (char c : s1) {
            need[c - 'a']++;
        }

        for (int r = 0; r < static_cast<int>(s2.length()); r++) {
            window[s2[r] - 'a']++;

            if (r - l + 1 > s1.length()) {
                window[s2[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == s1.length() && window == need) {
                return true;
            }
        }
        
        return false;
    }
};
