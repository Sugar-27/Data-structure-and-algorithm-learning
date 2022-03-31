// 乘积数组：列出来横坐标为a[i]，纵坐标为b[i]的数组图，左上角到右下角对角线为1
// 先求下三角，再求上三角，最终合成结果

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int length = a.size();
        if (length == 0)    return {};
        vector<int> b(length, 0);
        b[0] = 1;
        int temp = 1;
        // 求下三角乘积
        for (int i = 1; i < length; ++i) {
            b[i] = b[i - 1] * a[i - 1];
        }
        // 求上三角乘积
        for (int i = length - 2; i >= 0; --i) {
            temp *= a[i + 1];
            b[i] *= temp;
        }
        return b;
    }
};

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> b(n, 1);
        for (int i = 1; i < n; ++i) {
            b[i] = b[i - 1] * a[i - 1];
        }
        vector<int> tmp(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            // tmp数组可以只用一个变量来维护
            tmp[i] = tmp[i + 1] * a[i + 1];
            b[i] *= tmp[i];
        }
        return b;
    }
};