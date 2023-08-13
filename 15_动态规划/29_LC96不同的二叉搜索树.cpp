// 官方题解：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution/
class Solution {
public:
    int numTrees(int n) {
      // 对于n个节点的二叉搜索树
      // 可以依次以1～n为根，设根节点为i
      // 因此左子树即1～i-1的二叉搜索树，右子树即i+1～n的二叉搜索树
      // 数量上总数量等于左子树的数量乘右子树的数量
      // 而另一方面，设dp[i]为以i为根的数量
      // 那么i+1~n的二叉搜索树其实就等于1～n-i的二叉搜索树数量
      // 对于1～n-i这棵树，每个节点等量地加上i就变成了i+1～n这棵树
      // 因此可以得到递推方程：dp[i] = sum_j(dp[j] * dp[i - j - 1])
      vector<int> dp(n + 1, 0);
      dp[0] = 1;
      dp[1] = 1;
      for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            // j是左子树的根节点
            dp[i] += dp[j] * dp[i - j - 1];
        }
        }
        return dp[n];
    }
};