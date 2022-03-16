// 题解：https://leetcode-cn.com/problems/jump-game-ii/solution/dong-tai-gui-hua-jie-fa-by-alchemist-5r/
// 基本动规
class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e9);

        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};

// 优化
// 忽略掉不能到达的点，那些点进行dp运算没有意义
// 只考虑当前点能到达的点，然后进行计算最小步数
class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e9);

        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j >= n) {
                    return dp[n - 1];
                }
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[n - 1];
    }
};

// 补个贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int ans = 0;
        for (int i = 0; i < n;) {
            int right = nums[i] + i;
            if (right >= n - 1) return ans + 1;
            int nx = right;
            for (int j = i; j <= right; ++j) {
                if (j + nums[j] > nx + nums[nx]) {
                    nx = j;
                }
            }
            i = nx;
            ++ans;
        }
        return ans;
    }
};