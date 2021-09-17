class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        s.push(val);
        if (preMin.empty())
            preMin.push(val);
        else
            preMin.push(val < preMin.top() ? val : preMin.top());
    }

    void pop() {
        s.pop();
        preMin.pop();
    }

    int top() { return s.top(); }

    int getMin() { return preMin.top(); }

   private:
    stack<int> preMin;
    stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */