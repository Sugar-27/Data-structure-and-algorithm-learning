class Solution {
   public:
    int minimumEffort(vector<vector<int>>& tasks) {
        /*消耗(actual)小，门槛（minimum）大，是先做的条件
        按actual + (-minimum)排序*/
        int ans = 0;  // 任务全部做完（什么也不用再做了）的时候，还需要0的能量
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        // 正序做任务，但计算要倒序
        // 倒序计算完成恰好完成所有任务的能量即为最小能量
        for (int i = tasks.size() - 1; i >= 0; --i) {
            //         minimum        energy + actual
            ans = max(tasks[i][1], ans + tasks[i][0]);
        }
        return ans;
    }
};