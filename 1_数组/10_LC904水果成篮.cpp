// 双指针做法
// 双指针的模版
/*
确定左指针
for 右指针 {
    把右指针内容加入答案
    while (窗口内容不合规) {
        移动左指针
    }
    更新答案（此时一定是合规的），窗口大小：r - l + 1
}
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, ans = 0;
        unordered_map<int, int> mp;
        for (int r = 0; r < n; ++r) {
            mp[fruits[r]]++;
            while (mp.size() > 2) {
                if (--mp[fruits[l]] == 0) mp.erase(fruits[l]);
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};