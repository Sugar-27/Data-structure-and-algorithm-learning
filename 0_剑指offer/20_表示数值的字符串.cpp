// 分类讨论
// 题解：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/solution/jian-zhi-offer-20-biao-shi-shu-zhi-de-zi-l65a/

/*
. 出现正确情况：只出现一次（即前面没出现过），且出现在 e 或 E 的前面
    因为如果前面出现过 e/E 再出现 . 说明 e/E 后面跟着小数，不符合题意

e 或 E
出现正确情况：只出现一次（即前面没出现过），且出现前有数字，出现后后面也得有数字

+、- 出现正确情况：只能在开头 和 e 或 E 的后一位
*/

class Solution {
   public:
    bool isNumber(string s) {
        int n = s.length();
        int numFlag = false, hasE = false, hasPoint = false;
        int l = 0, r = n - 1;
        // 去掉首尾空格
        while (l < n && s[l] == ' ')
            ++l;
        while (r >= 0 && s[r] == ' ')
            --r;
        for (int i = l; i <= r; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                numFlag = true;
            } else if (s[i] == '.' && !hasPoint && !hasE) {
                // 如果是'.'，则必须之前没有'.'也没有'e'
                hasPoint = true;
            } else if ((s[i] == 'e' || s[i] == 'E') && !hasE && numFlag) {
                hasE = true;
                // 因为e后面必须要有数字，将numFlag设为false可以由结果自动判别e后有没有数字
                numFlag = false;
            } else if ((s[i] == '+' || s[i] == '-') &&
                       (i == l || s[i - 1] == 'e' || s[i - 1] == 'E')) {
                // 正负号只能出现在第一位或者e后的第一位
                continue;
            } else {
                return false;
            }
        }
        return numFlag;
    }
};