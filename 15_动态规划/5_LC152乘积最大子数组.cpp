class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    vector<float> dp_max(n, 1);
    vector<float> dp_min(n, 1);
    dp_max[0] = dp_min[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      dp_max[i] = max((float)nums[i],
                      max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
      dp_min[i] = min((float)nums[i],
                      min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
    }
    return *max_element(dp_max.begin(), dp_max.end());
  }
};