class Solution {
   public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(nums[i]) != mp.end()) {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            } else {
                mp[nums[i]] = {1, i, i};
            }
        }
        int ans = 1e9;
        int compare = mp[nums[0]][0];
        for (auto key_val : mp) {
            if (key_val.second[0] == compare) {
                compare = key_val.second[0];
                ans = min(ans, key_val.second[2] - key_val.second[1] + 1);
            } else if (key_val.second[0] > compare) {
                compare = key_val.second[0];
                ans = key_val.second[2] - key_val.second[1] + 1;
            }
        }
        return ans;
    }
};