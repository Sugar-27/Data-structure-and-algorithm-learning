class Solution {
   public:
    int calculate(string s) {
        stack<char> ops;        // 栈存运算符
        vector<string> tokens;  // vector存后缀表达式
        bool numStart = false;  // 表示是否开始存数字
        bool needs_zero = true;
        long long val = 0;

        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                val = val * 10 + ch - '0';
                numStart = true;
                continue;
            } else if (numStart) {
                numStart = false;
                tokens.push_back(to_string(val));
                needs_zero = false;
                val = 0;
            }

            if (ch == ' ')
                continue;

            if (ch == '(') {
                ops.push(ch);
                needs_zero = true;
                continue;
            }
            if (ch == ')') {
                while (ops.top() != '(') {
                    tokens.push_back(string(1, ops.top()));
                    ops.pop();
                    continue;
                }
                needs_zero = false;
                ops.pop();
                continue;
            }

            // 处理+-*/
            if (needs_zero == true)
                tokens.push_back("0");
            while (!ops.empty() && getRank(ops.top()) >= getRank(ch)) {
                // 前面的符号优先级更高，就可以计算了，例如1*2+3，遇到+时，*就可以算了
                tokens.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(ch);
            needs_zero = true;
        }

        if (numStart)
            tokens.push_back(to_string(val));
        while (!ops.empty()) {  // 最后剩余的符号都要取出来
            tokens.push_back(string(1, ops.top()));
            ops.pop();
        }
        return evalRPN(tokens);
    }

    int getRank(char ch) {
        if (ch == '+' || ch == '-')
            return 1;
        if (ch == '*' || ch == '/')
            return 2;
        return 0;
    }

    long long evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = stk.top();
                stk.pop();
                long long a = stk.top();
                stk.pop();
                stk.push(eval(a, b, token));
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }

    long long eval(int a, int b, string token) {
        if (token == "+")
            return a + b;
        if (token == "-")
            return a - b;
        if (token == "*")
            return a * b;
        if (token == "/")
            return a / b;
        return -1;
    }
};