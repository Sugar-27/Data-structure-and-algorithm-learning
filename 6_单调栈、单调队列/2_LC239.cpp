// 双端队列解法
// 使用双端队列，里面存可能的最大值的坐标，每次更新的时候只要队头的坐标合法则队头是最大值
// 对于队尾，每次更新的时候如果当前的值比队尾大，则意味着现在的队尾永远都不会用上了，因此用当前的值替换队尾，直到队尾的值比当前的值大
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // 双端队列，存下标（代表时间）
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            // 保证队头合法性
            while (!q.empty() && q.front() <= i - k)
                q.pop_front();
            // 维护队列单调性，插入新的选项
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            // 取队头更新答案
            if (i >= k - 1)
                ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
/*
1 3 [-1 -3 5] 3 6 7

// 时间：expire_time(-1) < expire_time(-3) < expire_time(5)
// 值大小：-1 < -3 < 5
// 求max

// 冗余：一个下标i一个下标j，如果i<j，并且nums[i]<=nums[j]，i是冗余

1 [3, -1, -3] -5 3 6 7
1, 3, [-1, -3, -5] 3 6 7

5*/


// 优先队列解法：懒惰删除
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k - 1; ++i) {
            q.push({nums[i], i});
        }
        for (int i = k - 1; i < n; ++i) {
            q.push({nums[i], i});
            while (!q.empty() && q.top().second + k <= i)
                q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }
};