class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valToIndex;
        for (int i = 0; i < nums.size(); ++i) {
            if (valToIndex.find(target - nums[i]) != valToIndex.end())  return {valToIndex[target - nums[i]], i};
            valToIndex[nums[i]] = i;
        }
        return {};
    }
};