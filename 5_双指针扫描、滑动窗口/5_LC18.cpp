// 与LC15思路一致
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])    continue;
            if (i + 3 < nums.size() && (long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)  break;
            vector<vector<int>> tmp = threeSum(nums, target - nums[i], i + 1);
            for (auto& t : tmp) {
                ans.push_back({nums[i], t[0], t[1], t[2]});
            }
        }
        return ans;
    }
private:
    vector<vector<int>> threeSum(vector<int>& nums, int target, int start) {
        vector<vector<int>> ans;
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1])    continue;
            int r = nums.size() - 1;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])    continue;
                while (j < r && nums[j] + nums[r] > target - nums[i]) --r;
                if (j < r && nums[j] + nums[r] == target - nums[i])   ans.push_back({nums[i], nums[j], nums[r]});
            }
        }
        return ans;
    }
};