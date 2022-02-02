// 哈希表：时间复杂度O(n), 空间复杂度O(n)
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& n : nums) {
            mp[n]++;
            if (mp[n] > nums.size() / 2)
                return n;
        }
        return -1;
    }
};

// 优化：投票法，时间复杂度O(n)，空间复杂度O(1)
// 本质上是在统计众数，因为题目说了一定存在数量大于n / 2的数，因此直接找众数即可
// 众数的数量会多于其他的数字
// 因此统计一个数字以及其数量，遇到相同的数字就加数量，遇到不同的数字就减数量
// 数量不够减的时候就换数字，最后剩下的数字就是数量最多的数字
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int num = -1;
        int cnt = 0;
        for (int& n : nums) {
            if (n == num) {
                cnt++;
            } else if (--cnt < 0) {
                num = n;
                cnt = 1;
            }
        }
        return num;
    }
};