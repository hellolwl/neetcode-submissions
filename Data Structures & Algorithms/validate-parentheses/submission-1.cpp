class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char c : s) {
            if (c == '[') {
                stk.push(']');
            } else if (c == '{') {
                stk.push('}');
            } else if (c == '(') {
                stk.push(')');
            } else if ((c == ']') && !stk.empty() && (stk.top() == ']')) {
                    stk.pop();
            } else if ((c == '}') && !stk.empty() && (stk.top() == '}')) {
                    stk.pop();
            } else if ((c == ')') && !stk.empty() && (stk.top() == ')')) {
                    stk.pop();
            } else {
                return false;
            }
        }

        if (stk.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
