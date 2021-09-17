//盛水的量由最短的那根决定
//短的算完就没有用了，因为长的那根已经是离它最远的木棍了
//最左端头的i与最右端尾的j一起移动，每次移动短的那一根

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;
        while (i < j) {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if (height[i] == height[j]) ++i, --j;
            else if (height[i] < height[j]) ++i;
            else --j;
        }
        return ans;
    }
};