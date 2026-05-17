class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;

        for (string t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int res = 0;
                int val1 = stoi(s.top());
                s.pop();
                int val2 = stoi(s.top());
                s.pop();
                if (t == "+") res = val2 + val1;
                else if (t == "-") res = val2 - val1;
                else if (t == "*") res = val2 * val1;
                else res = val2 / val1;
                s.push(to_string(res));
            } else {
                s.push(t);
            }
        }
        
        return stoi(s.top());
    }
};
