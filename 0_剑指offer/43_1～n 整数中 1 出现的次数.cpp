// 对于数字n，统计每一位为1时的个数，把所有位的加起来就是总的个数
// 比如数字 357
// 统计个位，则就是001 ～ 351，一共有0-135共136个1
// 统计十位，则就是010 ～ 319，一共有0-139共140个1
// 最终规律为，将一个数分为低位、高位、当前位三部分
// 其中，当前位表示我要统计当前位为1的总数
// 低位就是比当前位低的数字，高位就是比当前位高的数字
// 比如12345，当前位是3，则低位是45，高位是12
// 用一个digit表示当前位的进制，比如个位是1，十位是10，百位就是100
// 答案规律统计如下，当前位为0，则统计个数为高位*digit
// 当前位为1，统计个数为高位*digit + 低位 + 1
// 当前位为2-9，统计个数为（高位+1）*digit
class Solution {
   public:
    int countDigitOne(int n) {
        long long low = 0, high = n / 10, cur = n % 10, digit = 1;
        int ans = 0;
        while (high != 0 || cur != 0) {
            if (cur == 0) {
                ans += high * digit;
            } else if (cur == 1) {
                ans += high * digit + low + 1;
            } else {
                ans += (high + 1) * digit;
            }
            low = low + cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return ans;
    }
};