class MyQueue {
    stack<int> temp1, temp2;

public:
    MyQueue() {}

    void push(int x) {
        while (!temp2.empty()) {
            temp1.push(temp2.top());
            temp2.pop();
        }
        temp1.push(x);
        while (!temp1.empty()) {
            temp2.push(temp1.top());
            temp1.pop();
        }
    }

    int pop() {
        int x = temp2.top();
        temp2.pop();
        return x;
    }

    int peek() { return temp2.top(); }

    bool empty() { return temp2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */