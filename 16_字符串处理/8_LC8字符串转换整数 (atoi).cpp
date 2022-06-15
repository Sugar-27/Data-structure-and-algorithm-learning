// 模拟，要注意范围处理
class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int i = 0, n = s.length();
        // 清除前缀空格
        while (i < n && s[i] == ' ') ++i;
        bool neg = false;
        // 判断正负
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') neg = true;
            ++i;
        }
        // 处理数字
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                int tmp = s[i] - '0';
                // 范围处理，避免超范围，用-和/来做运算
                if (ans > (INT_MAX - tmp) / 10) 
                    return neg ? INT_MIN : INT_MAX;
                ans = ans * 10 + tmp;
            }
            else break;
            ++i;
        }
        return neg ? -ans : ans;
    }
};