class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for (string str : strs) {
            int len = str.length();
            result += std::to_string(len) + "#";
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            int len = std::stoi(s.substr(i, j - i));
            i = j + 1;
            result.push_back(s.substr(i, len));
            i += len;
        }

        return result;
    }
};
