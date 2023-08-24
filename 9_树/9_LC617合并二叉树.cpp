/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// 新做法：返回一棵全新的树，完全不修改原先的两棵树
class Solution {
public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2)
      return nullptr;
    if (!root1)
      return copyTree(root2);
    if (!root2)
      return copyTree(root1);
    auto node = new TreeNode(root1->val + root2->val);
    node->left = mergeTrees(root1->left, root2->left);
    node->right = mergeTrees(root1->right, root2->right);
    return node;
  }

private:
  TreeNode *copyTree(TreeNode *root) {
    if (!root)
      return nullptr;
    auto node = new TreeNode(root->val);
    node->left = copyTree(root->left);
    node->right = copyTree(root->right);
    return node;
  }
};

// 老做法：会修改原始的树
class Solution {
public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2)
      return nullptr;

    // 创建新节点，新节点的值取决于root1和root2的值，如果为nullptr则认为值为0（因为一定会有一个有值）
    TreeNode *root = new TreeNode(0);
    root->val += root1 ? root1->val : 0;
    root->val += root2 ? root2->val : 0;

    // 递归找左右子树
    root->left = mergeTrees(root1 ? root1->left : nullptr,
                            root2 ? root2->left : nullptr);
    root->right = mergeTrees(root1 ? root1->right : nullptr,
                             root2 ? root2->right : nullptr);
    return root;
  }
};