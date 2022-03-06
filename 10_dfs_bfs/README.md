## DFS与BFS比较：

#### DFS更适合搜索树形状态空间

* 递归本来就会产生树的结构
* 可以用一个全局变量维护状态中较为复杂的信息（例如：子集方案，排列方案）
* 不需要队列，节省空间

#### BFS适合求“最小代价”、“最小步数”的题目

* BFS是按层次搜索，第 `k`步搜完才会搜 `k+1`步，在任一时刻队列中至多有两层

#### 在状态空间为一般的图时（即需要判重），DFS和BFS差不多

* 按个人喜好来即可

## 关于地图类的搜索题

### 基本套路：

1. 先找给定地图范围，也即确定`int m, n`，`m = board.size()`,`n = board[0].size()`，其中`m`是行数而`n`是列数

2. 然后确定方向，也即
   `const int dx[4] = {-1, 0, 1, 0};`
   `const int dy[4] = {0, -1, 0, 1};`
   也就是按照[上，左，下，右]的顺序来，如果有方向要求，向左转就是`(dir + 1) % 4`，向右转就是`(dir - 1 + 4) % 4`

3. 写子程序，按照规则完成任务

   ```c++
   void dfs(vector<vector<char>>& board, int x, int y, char ch, bool record) {
           visit[x][y] = true;
     			// 要完成的任务
           if (record) {
               rec.insert({x, y});
           }
     			// 要完成的任务
           board[x][y] = ch;
           for (int i = 0; i < 4; ++i) {
             	// 遍历地图
               int nx = x + dx[i];
               int ny = y + dy[i];
               if (nx < 0 || ny < 0 || nx >= m || ny >= n || visit[nx][ny]) {
                   continue;
               }
             	// 达到条件可以继续遍历
               if (board[nx][ny] == 'O')
                   dfs(board, nx, ny, ch, record);
           }
       }
   ```

   
