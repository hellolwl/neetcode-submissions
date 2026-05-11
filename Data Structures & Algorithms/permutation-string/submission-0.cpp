class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (int i = 0; i < s1.length(); i++) {
            map1[s1[i]]++;
            map2[s2[i]]++;
        }

        if (map1 == map2) {
            return true;
        }

        for (int right = s1.length(); right < s2.length(); right++) {
            map2[s2[right]]++;

            char out = s2[right - s1.length()];
            map2[out]--;
            if (map2[out] == 0) {
                map2.erase(out);
            }

            if (map1 == map2) {
                return true;
            }
        }
        
        return false;
    }
};
