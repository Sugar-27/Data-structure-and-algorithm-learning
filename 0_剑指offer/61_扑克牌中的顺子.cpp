// 解题关键：
// 1.所有牌无重复，可使用vector数组记录，或者set或者哈希表
// 2.去掉大小王后五张牌里最大值减去最小值的插值要小于5

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<int> rec(14, 0);
        int maxNum = 0, minNum = 14;
        for (int num : nums) {
            if (!num)   continue;
            if (rec[num] == 1)  return false;
            rec[num]++;
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
        }
        return maxNum - minNum < 5;
    }
};