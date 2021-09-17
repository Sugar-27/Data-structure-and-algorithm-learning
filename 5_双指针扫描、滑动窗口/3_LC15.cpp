//三数之和，利用公式变换把它变成两数之和

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // nums[i] + nums[j] + nums[k] = 0
        // nums[j] + nums[k] = -nums[i]
        // i < j < k
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> allTwoSum = twoSum(nums, i + 1, -nums[i]);
            for (vector<int>& jk : allTwoSum) {
                ans.push_back({nums[i], jk[0], jk[1]});
            }
        }
        return ans;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> ans;
        int k = nums.size() - 1;
        for (int j = start; j < nums.size(); ++j) {
            if (j > start && nums[j] == nums[j - 1])    continue;
            while (j < k && nums[j] + nums[k] > target)  --k;
            if (j < k && nums[j] + nums[k] == target) {
                ans.push_back({nums[j], nums[k]});
            }
        }
        return ans;
    }
};