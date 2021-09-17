class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // pair<val, index>
        vector<pair<int, int>> record;
        for (int i = 0; i < nums.size(); ++i) {
            record.push_back(make_pair(nums[i], i));
        }
        sort(record.begin(), record.end());
        int j = record.size() - 1;
        for (int i = 0; i < record.size(); ++i) {
            while (i < j && record[i].first + record[j].first > target) --j;
            if (i < j && record[i].first + record[j].first == target) {
                return {record[i].second, record[j].second};
            }
        }
        return {};
    }
};