class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = {1, i, i};
            } else {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            cnt = max(cnt, mp[nums[i]][0]);
        }
        int ans = INT_MAX;
        for (auto& kV : mp) {
            if (kV.second[0] == cnt) {
                ans = min(ans, kV.second[2] - kV.second[1] + 1);
            }
        }
        return ans;
    }
};