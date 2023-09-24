class Solution {
public:
  int mergeStones(vector<int> &stones, int k) {
    int n = stones.size();
    stones.insert(stones.begin(), 0);
    vector<int> sums(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      sums[i] = sums[i - 1] + stones[i];
    }
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, 1e9)));
    for (int i = 0; i <= n; ++i)
      dp[i][i][1] = 0;

    for (int len = 2; len <= n; ++len) {
      for (int l = 1; l <= n - len + 1; ++l) {
        int r = l + len - 1;
        for (int i = 2; i <= k; ++i) {
          // 这里本质上可以将dp[l][r][i]分成两个子问题
          // 1.dp[l][p][j], 2.dp[p + 1][r][i - j]
          // 即l~p合成j堆，以及p+1~r合成i-j堆
          // 但事实上，这块不需要枚举j，因为不管j怎么划分结果都是一样的
          // 只需要考虑j=1这一种情况即可，另外一堆就是i-1
          // 也就是只考虑了第一堆在哪一段，也就是l~p是一段，后面的p+1~r合成i-1段
          for (int p = l; p < r; ++p) {
            dp[l][r][i] = min(dp[l][r][i], dp[l][p][1] + dp[p + 1][r][i - 1]);
          }
        }
        // 能合成一堆的前提是能合成K堆，因此也就是合成K堆的成本再加上这K堆的合
        dp[l][r][1] = min(dp[l][r][1], dp[l][r][k] + sums[r] - sums[l - 1]);
      }
    }

    if (dp[1][n][1] >= 1e9)
      return -1;
    return dp[1][n][1];
  }
};

// 更快的做法
class Solution {
public:
  int mergeStones(vector<int> &stones, int k) {
    int n = stones.size();
    // 直接判断是否可以合成1堆
    // 从 n 堆变成 1 堆，需要减少 n−1 堆。而每次合并都会减少 k−1 堆，所以 n−1 必须是 k−1 的倍数
    if ((n - 1) % (k - 1) != 0)
      return -1;

    vector<int> sums(n + 1, 0);
    stones.insert(stones.begin(), 0);
    for (int i = 1; i <= n; ++i) {
      sums[i] = sums[i - 1] + stones[i];
    }
    // dp[i][j] i - j合并成一堆的最小成本
    // dp[i][j]合并有隐藏含义，直接判断i-j的长度len是否可以合成一堆，可以合成一堆的话就直接合成一堆
    // 如果不能，则保存的是两块的内容，dp[i][m] + dp[m + 1][j]
    // 保证m - i + 1 是 k - 1的倍数
    // 如果可以合成，再求一下前缀和即可
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 0; i <= n; ++i)
      dp[i][i] = 0;
    for (int len = 2; len <= n; ++len) {
      for (int l = 1; l + len - 1 <= n; ++l) {
        int r = l + len - 1;
        for (int i = l; i < r; i += k - 1) {
          dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
        }
        if ((len - 1) % (k - 1) == 0) {
          dp[l][r] += sums[r] - sums[l - 1];
        }
      }
    }
    return dp[1][n];
  }
};