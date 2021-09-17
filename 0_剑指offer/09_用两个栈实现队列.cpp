class CQueue {
public:
    CQueue() {
        while (!append.empty()) {
            append.pop();
        }
        while (!del.empty()) {
            del.pop();
        } 
    }
    
    void appendTail(int value) {
        append.push(value);
    }
    
    int deleteHead() {
        if (del.empty()){
            while (!append.empty()) {
                del.push(append.top());
                append.pop();
            }
        }
        if (del.empty())    return -1;
        else {
            int ans = del.top();
            del.pop();
            return ans;
        }
    }
private:
    stack<int> append;
    stack<int> del;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */