// 在一个数组中找到两个最大数字，他俩的异或值最大
class Solution {
public:
  int findMaximumXOR(vector<int> &nums) {
    // 基本思路：
    // 假设有两个数nums[i]和nums[j]，始终有i < j
    // 只需要构建一个Trie树，去遍历nums[j]，因为有i < j的假设，因此每次遍历到j时，nums[i]一定在树中了
    // 查找Trie树的思想就是每一位都尽可能和j的那一位不一样，这样子这一位异或后就是1，同时优先高位不同
    int ans = 0;
    for (auto num : nums) {
      // 每遍历到一个num就把它加入到Trie树中
      add(num);
      // 查找nums[i]，这个nums[i]就是nums[j]之前跟nums[j]能构成最大异或的值
      auto num2 = getVal(num);
      // ans取两者最大的，遍历结束即找到整个数组中最大的
      ans = max(ans, num ^ num2);
    }
    return ans;
  }

private:
  // 构建Trie树
  class Node {
  public:
    // 每个Node节点有两个子节点，ns[0]表示这一位为0时的子节点，ns[1]表示这一位为1时的子节点
    vector<Node *> ns = vector<Node *>(2, nullptr); 
  };
  Node *root = new Node();
  void add(int x) {
    auto p = root;
    // int类型，一共32位
    for (int i = 31; i >= 0; --i) {
      // 当前位的数值
      auto idx = (x >> i) & 1;
      if (p->ns[idx] == nullptr)
        p->ns[idx] = new Node();
      p = p->ns[idx];
    }
  }
  int getVal(int x) {
    // ans记录最终的结果
    int ans = 0;
    auto p = root;
    for (int i = 31; i >= 0; --i) {
      // a是当前x这一位的数值，b是跟他相反的数值，只要可以走b就优先走b，这样异或后高位是1
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