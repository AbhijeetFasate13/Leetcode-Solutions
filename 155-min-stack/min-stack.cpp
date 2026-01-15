class MinStack {
    stack<int> min, data;

public:
    MinStack() {}

    void push(int val) {
        if (min.empty() or val <= min.top())
            min.push(val);
        data.push(val);
    }

    void pop() {
        if (data.empty())
            return;
        if (min.top() == data.top()) {
            min.pop();
        }
        data.pop();
    }

    int top() { return data.top(); }

    int getMin() { return min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */