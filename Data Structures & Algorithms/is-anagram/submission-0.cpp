class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        std::vector<int> count(26, 0);
        int i = 0;
        for (i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }

        for (i = 0; i < t.length(); i++) {
            count[t[i] - 'a']--;
        }

        bool all_zero = std::all_of(count.begin(), count.end(), [](int i) { return i == 0; });

        return all_zero;
    }
};
