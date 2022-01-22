class Solution {
   public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = -1000000000;
        deque<int> q;  // 双端队列存下标
        for (int i = 0; i < points.size(); i++) {
            // 求上界：j<=i-1，下界：x[j]>=x[i]-k
            // 这个范围中 y[j]-x[j] 的最大值
            // 考虑两个选项 j1<j2
            // 写出 j1 比 j2 优的条件
            // y[j1]-x[j1] > y[j2]-x[j2]
            // 1. 队头合法性
            // x[j]: points[q.front()][0]
            while (!q.empty() && points[q.front()][0] < points[i][0] - k)
                q.pop_front();
            // 2. 取队头为最优解
            // y[i]: points[i][1]
            // x[i]: points[i][0]
            // y[i] + x[i] + max{y[j] - x[j]}
            if (!q.empty())
                ans = max(ans, points[i][1] + points[i][0] +
                                   points[q.front()][1] - points[q.front()][0]);
            // 3. 维护队列单调性，队尾插入新选项i
            while (!q.empty() && points[q.back()][1] - points[q.back()][0] <=
                                     points[i][1] - points[i][0])
                q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};