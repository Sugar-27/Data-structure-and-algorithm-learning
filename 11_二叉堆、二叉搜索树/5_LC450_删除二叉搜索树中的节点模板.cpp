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
/*
解题思路：
二叉搜索树查询后继的模版题
使用一种通用的方法来解这道题，即可以同时满足树中存在节点（本题的要求）和这个值不存在于树中两种情况的后继。

思路如下：
对于给定查询的数值val，考虑如下几种情况：
当前root的值小于val，则如果该树有val的后继那一定是在root的右节点树上
当前root的值大于val，则如果该树有val的后继那一定是在root的坐节点树上
当前root的值等于val，则如果root有右子树，那么后继就存在于root右子树的左子树一路向左遍历的最后一个节点；如果root没有右子树，则后继应当存在于之前遍历过比它大的节点中；

因此，我们使用一个cur来遍历二叉搜索树，用一个ans记录所有比目标val大的值，并在遍历的过程中遇到比val大但比ans小的节点时更新ans
*/
class Solution {
   public:
    // 在以root为根的子树中删除key，返回新的根
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key) {
            if (root->left == nullptr)
                return root->right;  // 没有左子树，让right代替root的位置
            if (root->right == nullptr)
                return root->left;  // 没有右子树，让left代替root的位置
            TreeNode* next = root->right;
            while (next->left != nullptr)
                next = next->left;  // 找后继：右子树一路向左
            root->right = deleteNode(root->right, next->val);
            root->val = next->val;
        }
        // key在树的右子树里面
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        // key在树的左子树里面
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        return root;
    }
};