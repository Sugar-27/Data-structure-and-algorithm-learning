// 找多数元素，这个元素的数量是大于n / 2
// 用消消乐的思想来做，这个多数元素一定可以把其他所有的元素都消耗掉
// 用一个num来记录临时元素，用一个f记录它出现的次数，每次不同就将次数减一
// 如果这个f减到0，就更换临时数字然后把f重置为1，最后剩下的就是多数元素
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num = nums[0], f = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != num) {
                if (--f == 0) {
                    num = nums[i];
                    f = 1;
                }
            } else {
                ++f;
            }
        }
        return num;
    }
};