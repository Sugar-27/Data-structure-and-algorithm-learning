class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 合并做法
        // 维护当前覆盖的最远端
        // 判断一个区间是延续？还是新成立一段？
        // 看它的起点是在最远端之后还是之前
        /*[1, 5]  [2, 6] [3, 4] [6, 10]  [11 12]
        [1  5] 当前覆盖的最远端：5
        [2  6] 当前覆盖的最远端：6
        [3  4] 当前覆盖的最远端：6
        [6 10] 当前覆盖的最远端：10

        [11 12]*/
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
             });
        vector<vector<int>> ans;
        int left = intervals[0][0];
        int far = intervals[0][1];
        for (vector<int>& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            if (start <= far) {
                //延续
                far = max(far, end);
            } else {
                //另起一段
                ans.push_back({left, far});
                left = start;
                far = end;
            }
        }
        //处理掉最后一个段
        ans.push_back({left, far});
        return ans;
    }
};

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //差分做法
        /*[1, 5]  [2, 6] [3, 4] [6, 10]  [11 12]
           1 2 3 4 5 6 7 8 9 10 11 12
           1 1 1 1 1
             1 1 1 1 1
               1 1
                     1 1 1 1  1
                                  1 1

           +1      -1
             +1      -1
               +1-1
                     +1        -1
                               +1 -1
         count: 0
        把从1覆盖到6这个区间(左闭右开[1, 6))，看作2个事件：
        (a) 在1处，有一个事件：开始覆盖（次数+1）
        (b) 在6处，有一个事件：结束覆盖（次数-1）
        */
        // 产生2n个事件
        // 时间位置，时间情况(+1/-1)
        vector<pair<int, int>> events;
        int count = 0;
        int left;
        vector<vector<int>> ans;
        for (vector<int>& interval : intervals) {
            events.push_back(make_pair(interval[0], 1));
            events.push_back(make_pair(interval[1] + 1, -1));
        }
        sort(events.begin(), events.end());
        for (pair<int, int>& event : events) {
            if (count == 0) {  //一段的开始
                left = event.first;
            }
            count += event.second;
            if (count == 0) {  //一段的结束
                ans.push_back({left, event.first - 1});
            }
        }
        return ans;
    }
};