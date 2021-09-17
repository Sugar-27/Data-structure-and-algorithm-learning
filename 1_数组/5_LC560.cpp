/*
前缀和加哈希表进行优化
*/
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pre = 0, ans = 0;
        mp[0] = 1;
        for (int& num : nums) {
            //求前缀和的过程优化版，因为每次只用当前的前缀和，因此不需要另开空间记录前缀和，前缀和出现的次数记录在哈希表中
            pre += num;
            if (mp.find(pre - k) != mp.end()) {
                ans += mp[pre - k];
            }
            mp[pre]++;  //次数加一
        }
        return ans;
    }
};