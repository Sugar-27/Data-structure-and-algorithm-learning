/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
*/
// https://leetcode-cn.com/problems/number-of-islands/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n, false));
        int ans = 0;  //岛的数量
        //遍历数组
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visit[i][j]) {
                    // dfs(grid, i, j);
                    bfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }

   private:
    //广搜, 从sx、sy出发bfs
    void bfs(vector<vector<char>>& grid, int sx, int sy) {
        //广搜需要队列
        queue<pair<int, int>> q;
        //第一步，push起点
        q.push(make_pair(sx, sy));
        //入队后立即标记已访问
        visit[sx][sy] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            //拓展所有出边
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    continue;
                }
                if (grid[nx][ny] == '1' && !visit[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    // bfs入队时标记visit
                    visit[nx][ny] = true;
                }
            }
        }
    }

    //深搜
    void dfs(vector<vector<char>>& grid, int x, int y) {
        visit[x][y] = true;
        //四个方向
        for (int i = 0; i < 4; ++i) {
            // next x, next y
            int nx = x + dx[i];
            int ny = y + dy[i];
            //访问数组前先判断合法性
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }
            //如果下一个位置是1且没有被访问过则递归
            if (grid[nx][ny] == '1' && !visit[nx][ny]) {
                dfs(grid, nx, ny);
            }
        }
    }

    int m;                       //记录行数（水域高度）
    int n;                       //记录列数（水域宽度）
    vector<vector<bool>> visit;  //定义一个记录访问情况的数组
    //定义方向数组，行号列号，共四个方向，dx[0]dy[0]表示左移
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
};