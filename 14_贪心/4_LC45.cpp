class Solution {
   public:
    int jump(vector<int>& nums) {
        int now = 0, ans = 0;
        while (now < nums.size() - 1) {
            if (nums[now] == 0)
                return -1;
            int right = now + nums[now];  //可到达的地方[now + 1, right]
            if (right >= nums.size() - 1)
                return ans + 1;
            int next = now + 1;
            for (int i = now + 2; i <= right; ++i) {
                //遍历可到达的地方，选择一个下一次能跳最远的点
                int nextRight = i + nums[i];
                if (nextRight > next + nums[next])
                    next = i;
            }
            now = next;
            ++ans;
        }
        return ans;
    }
};