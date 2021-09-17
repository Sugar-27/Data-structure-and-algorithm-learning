// 位运算
// 根据与运算定义，设二进制数字n，则有：
//     (1)：若 n & 1 = 0，则 n 二进制最右一位为0；
//     (2)；若 n & 1 = 1，则 n 二进制最右一位为1。
// 因此：进行循环判断，每次判断最右位是否为1，然后右移一位
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            if (n & 1 == 1) ++ans; //判断最右位是否为1，如果是则答案加一
            n >>= 1; // 右移一位
        }
        return ans;
    }
};