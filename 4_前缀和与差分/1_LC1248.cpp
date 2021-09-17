//前缀和+哈希表，不够快

class Solution {
   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + (nums[i] & 1);
        }

        unordered_map<int, int> mp;
        int ans = 0;
        for (auto x : sums) {
            ans += mp[x - k];
            mp[x]++;
        }
        return ans;
    }
};

//因为将原始数组的全部元素变为了0，1
//因此可以使用数组对哈希表进行优化
class Solution {
   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        vector<int> count(n + 1, 0);
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + (nums[i] % 2);
        }

        int ans = 0;
        for (int s : sum) {
            if (s - k >= 0)
                ans += count[s - k];
            count[s]++;
        }
        return ans;
    }
};