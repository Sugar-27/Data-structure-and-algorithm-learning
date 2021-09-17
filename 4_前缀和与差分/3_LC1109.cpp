// 差分模板题，先利用差分的特性找到影响，然后对于差分数组求前缀和得到实际结果

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> delta(n + 2, 0);
        for (vector<int> booking : bookings) {
            int fir = booking[0];
            int last = booking[1];
            int seats = booking[2];
            delta[fir] += seats;
            delta[last + 1] -= seats;
        }

        vector<int> sum(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + delta[i];
        }

        for (int i = 1; i <= n; ++i) {
            sum[i - 1] = sum[i];
        }
        sum.pop_back();
        return sum;
    }
};

// 任何对于区间的操作，可以转化为两个关键点（事件）
// 事件的影响从l开始，在r+1处消失
// 累加影响得到答案
// l +d    r+1   -d
   1  2  3  4  5
  10    -10
     20    -20
     25          (-25)
  10 45 -10 -20 0
  10 55 45  25 25