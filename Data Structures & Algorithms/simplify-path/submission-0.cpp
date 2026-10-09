class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr_name;
        stringstream ss(path);

        while (getline(ss, curr_name, '/')) {
            if (curr_name.empty()) continue;
            if (curr_name == "..") {
                if (!st.empty()) st.pop_back();
            } else if (!curr_name.empty() && curr_name != ".") {
                st.push_back(curr_name);
            }
        }

        string result = "/";
        for (int i = 0; i < st.size(); i++) {
            if (i > 0) {
                result += "/";
            }

            result += st[i];
        }
        
        return result;
    }
};