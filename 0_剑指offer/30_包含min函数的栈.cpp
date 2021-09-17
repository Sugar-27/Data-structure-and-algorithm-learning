class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if (preMin.empty()) preMin.push(x);
        else if (preMin.top() >= x) preMin.push(x);
    }
    
    void pop() {
        if (preMin.top() == s.top())    preMin.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return preMin.top();
    }
private:
    stack<int> preMin;
    stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */