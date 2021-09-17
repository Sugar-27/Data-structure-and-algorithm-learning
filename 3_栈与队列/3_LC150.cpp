class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(cacl(a, b, token));
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }

    int cacl(int a, int b, string token) {
        if (token == "+")
            return a + b;
        else if (token == "-")
            return a - b;
        else if (token == "*")
            return a * b;
        else if (token == "/")
            return a / b;
        return -1;
    }
};