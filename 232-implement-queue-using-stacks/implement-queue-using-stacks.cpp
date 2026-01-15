class MyQueue {
    stack<int> data, removalHelper;
    int front;

public:
    MyQueue() {}

    void push(int x) {
        data.push(x);
        if (data.size() == 1)
            front = data.top();
    }

    int pop() {
        if (data.empty())
            return -1;
        int sz = data.size();
        for (int i = 0; i < sz - 1; i++) {
            removalHelper.push(data.top());
            data.pop();
        }
        int val = data.top();
        data.pop();
        if (sz == 1)
            return val;
        for (int i = 0; i < sz - 1; i++) {
            if (i == 0) {
                front = removalHelper.top();
            }
            data.push(removalHelper.top());
            removalHelper.pop();
        }
        return val;
    }

    int peek() {
        if (data.empty())
            return -1;
        return front;
    }

    bool empty() { return data.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */