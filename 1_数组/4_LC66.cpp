/*
倒序处理数组，依次加一，若加一之后不为10则停止
全部处理完之后如果数组首位为0则补一个1在最前面
*/
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            digits[i]++;
            if (digits[i] < 10)
                break;
            else
                digits[i] = 0;
        }
        if (digits[0] == 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};