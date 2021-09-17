class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // pair<值，下标>
        priority_queue<pair<int,int>> q;
        for (int i = 0; i < k - 1; i++) q.push(make_pair(nums[i], i));
        for (int i = k - 1; i < nums.size(); i++) {
            q.push(make_pair(nums[i], i));
            while (q.top().second <= i - k) q.pop();  // 懒惰删除，检查堆顶下标是否在窗口内
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

// 懒惰删除
// 延迟到 当未删除的值 会影响答案时 再进行

[1, 3, -1] priority_queue
正解：[3, -1, -3] max:3
懒惰删除：[1, 3, -1, -3] max:3

正解：[-1, -3, 5] max:5
懒惰删除：[1, 3, -1, -3, 5] max:5

[-3  5  3] max:5
懒惰删除：[1, 3, -1, -3, 5, 3] max:5


如果是：1,3,-1,-3,2,3,6,7

正解：[3, -1, -3] max:3
懒惰删除：[1, 3, -1, -3] max:3

正解：[-1, -3, 2] max:2
二元组（值，下标）
懒惰删除：[(1, 0), (-1, 2), (-3, 3), (2, 4)] max:2