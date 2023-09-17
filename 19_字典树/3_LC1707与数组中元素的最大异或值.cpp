// 一定先看421这一题
// 整体思路和421没区别，难点在于qs的处理，用map记录原始坐标会超时，事实上只需要直接在qs[i]后面加一个新的值表示坐标即可
// nums排序一下，qs再根据qs[i][1]排序一下，使得遍历qs的时候，Trie树中比limit限制高的数都还没加入进去即可
class Solution {
public:
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &qs) {
    int n = qs.size();
    for (int i = 0; i < n; ++i) {
      qs[i].push_back(i);
    }
    sort(nums.begin(), nums.end());
    sort(qs.begin(), qs.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    int idx = 0;
    vector<int> ans(n, -1);
    for (auto &q : qs) {
      int x = q[0], m = q[1], origin_idx = q[2];
      while (idx < nums.size() && nums[idx] <= m) {
        add(nums[idx++]);
      }
      if (idx == 0) {
        continue;
      } else {
        int y = getVal(x);
        int res = x ^ y;
        ans[origin_idx] = res;
      }
    }

    return ans;
  }

private:
  class Node {
  public:
    vector<Node *> ns = vector<Node *>(2, nullptr);
  };
  Node *root = new Node();
  void add(int x) {
    auto p = root;
    for (int i = 31; i >= 0; --i) {
      int a = (x >> i) & 1;
      if (p->ns[a] == nullptr)
        p->ns[a] = new Node();
      p = p->ns[a];
    }
  }
  int getVal(int x) {
    auto p = root;
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
      int a = (x >> i) & 1, b = 1 - a;
      if (p->ns[b] != nullptr) {
        ans |= (b << i);
        p = p->ns[b];
      } else {
        ans |= (a << i);
        p = p->ns[a];
      }
    }
    return ans;
  }
};