//单调栈模板题

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // 帮助我们在最后把栈清空
        stack<Rect> s;
        int ans = 0;
        // 每个矩形入栈、出栈各一次，2n=O(n)
        for (int h : heights) {
            int accumulated_width = 0;
            while (!s.empty() && s.top().height >= h) {
                accumulated_width += s.top().width;
                ans = max(ans, accumulated_width * s.top().height);
                s.pop();
            }
            s.push({h, accumulated_width + 1});
        }
        return ans;
    }

private:
    struct Rect {
        int height;
        int width;
    };
};