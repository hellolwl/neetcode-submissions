class MinStack {
    stack<int> data_s;
    stack<int> min_s;
public:
    MinStack() {

    }
    
    void push(int val) {
        data_s.push(val);
        if (min_s.empty() || val <= min_s.top()) {
            min_s.push(val);
        }

    }
    
    void pop() {
        if (!data_s.empty()) {
            int val = data_s.top();
            data_s.pop();
            if (val == min_s.top()) {
                min_s.pop();
            }

        }
    }
    
    int top() {
        return data_s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};
