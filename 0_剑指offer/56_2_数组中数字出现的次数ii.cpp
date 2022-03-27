// 位运算
// 原理：考虑数字的二进制形式，对于出现三次的数字，各二进制位出现的次数都是3的倍数
// 因此，统计所有数字的各二进制位中1的出现次数，并对3求余，结果则为只出现一次的数字

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};