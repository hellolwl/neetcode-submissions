class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {
            bool alive = true;

            while (alive && !st.empty() && st.top() > 0 && ast < 0) {
                int temp = st.top();

                if (abs(ast) > abs(temp)) {
                    st.pop();
                    // continue to check next top element in the stack
                } else if (abs(ast) == abs(temp)) {
                    st.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }

            if (alive) {
                st.push(ast);
            }
        }

        vector<int> res;
        res.reserve(st.size());

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};