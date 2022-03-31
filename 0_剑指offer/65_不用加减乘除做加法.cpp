class Solution {
public:
    int add(int a, int b) {
        // b其实代表着a要加的东西，第一次是无进位的加，后面都是计算产生的进位对于a的影响直到没有进位
        while (b != 0) {
            // 计算进位，是异或的关系，只有a和b的位均为1时才会产生进位，同时因为进位影响的是下一位所以左移
            int c = (unsigned int)(a & b) << 1; // C++不支持负数左移，强转为unsigned计算
            a ^= b; // 计算无进位的加
            b = c;  // 下一轮用来计算这一轮产生的进位
        } 
        return a;
    }
};