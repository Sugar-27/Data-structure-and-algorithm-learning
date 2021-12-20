class Solution {
   public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 0, right = 1000000001;
        while (left < right) {
            int mid = (right + left) / 2;
            if (ifMake(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (right == 1000000001)
            return -1;
        return right;
    }

   private:
    //分析第T天的开花情况，制作m束花，每朵花要连续的k朵
    bool ifMake(vector<int>& bloomDay, int m, int k, int mid) {
        int flowers = 0;
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= mid) {
                ++cnt;
                if (cnt == k) {
                    ++flowers;
                    if (flowers == m)
                        return true;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};