// 前缀和做法
// 用三个数组记录三组数据，一个是标准前缀和，一个是最小前缀和，一个是最大前缀和
// 对于数组[-1, 2, -3, 4]，到达下标2时也即到达数字-3时
// 标准前缀和为-1 + 2 + -3 = -2
// 最小前缀和为min(-1，-1 + 2，-1 + 2 + -3) = -2
// 最大前缀和为max(-1，-1 + 2，-1 + 2 + -3) = 1
// 对于不考虑首位相连时的情况，对于前i个数字，最大和就是sums[i] - minSums[i]，即标准前缀和减去最小前缀和
// 对于只考虑首位相连时的情况，最大和就是sum - (sums[i] - maxSums[i])
// 即全部的总和减去中间最小的子数组，(sums[i] - maxSums[i])表示的是子数组的最小和
class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return nums[0];
        nums.insert(nums.begin(), 0);
        vector<int> sums(n + 1, 0);
        vector<int> minSums(n + 1, 1e9);
        vector<int> maxSums(n + 1, -1e9);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += nums[i];
            sums[i] = sums[i - 1] + nums[i];
            minSums[i] = min(minSums[i - 1], sums[i - 1]);
            if (i == 2)
                maxSums[i] = sums[i - 1];
            else
                maxSums[i] = max(maxSums[i - 1], sums[i - 1]);
        }
        int ans1 = -1e9, ans2 = -1e9;
        for (int i = 1; i <= n; ++i) {
            ans1 = max(ans1, sums[i] - minSums[i]);
            ans2 = max(ans2, sum - (sums[i] - maxSums[i]));
        }
        return max(ans1, ans2);
    }
};

// 优化空间
class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return nums[0];
        nums.insert(nums.begin(), 0);
        vector<int> sums(n + 1, 0);
        int tmp1 = 1e9;
        int tmp2 = -1e9;
        int preSumMax = -1e9;
        int preSumMin = 1e9;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += nums[i];
            sums[i] = sums[i - 1] + nums[i];
            tmp1 = min(tmp1, sums[i - 1]);
            if (i >= 2)
                tmp2 = max(tmp2, sums[i - 1]);
            preSumMax = max(preSumMax, sums[i] - tmp1);
            preSumMin = min(preSumMin, sums[i] - tmp2);
        }
        return preSumMax >= sum - preSumMin ? preSumMax : sum - preSumMin;
    }
};

// 环形数组变成循环dp解法
// 用一个单调队列来维护i之前最小的前缀和
// 单调队列本质上就是一个滑动窗口，只是这个窗口的上下限由队列的入队出队规则来定
// 单调队列做法：
// 1.维护队头合法性 2.处理队头，队头是当下符合要求的最优解 3.插入队尾，维护队列的单调性
class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        nums.insert(nums.begin(), 0);
        vector<int> sums(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        deque<int> q;
        q.push_back(0);
        int ans = INT_MIN;
        for (int i = 1; i <= 2 * n; ++i) {
            while (!q.empty() && q.front() < i - n)
                q.pop_front();
            if (!q.empty()) {
                ans = max(ans, sums[i] - sums[q.front()]);
            }
            while (!q.empty() && sums[q.back()] >= sums[i])
                q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};

// 优化做法
// total为数组的总和
// maxSum为最大子数组和，minSum为最小子数组和
// curMax为包含当前元素的最大子数组和，curMin为包含当前元素的最小子数组和
class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0],
            curMin = 0;
        for (int& a : nums) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};