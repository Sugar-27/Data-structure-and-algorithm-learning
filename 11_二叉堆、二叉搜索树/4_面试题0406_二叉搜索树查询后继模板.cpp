/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return findSuccc(root, p->val);
    }

   private:
    TreeNode* findSuccc(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* ans = nullptr;
        while (curr != nullptr) {
            if (curr->val > val) {
                if (ans == nullptr ||
                    ans->val > curr->val) {  // case2：当后继存在于经过的点中
                    // 在所有大于val的点中找最小的
                    ans = curr;
                }
            }
            if (curr->val == val) {
                if (curr->right != nullptr) {
                    curr = curr->right;
                    while (curr->left != nullptr) {
                        curr = curr->left;
                    }
                    return curr;
                }
                break;
            }
            // 循环逻辑：当前值大于val往左走，小于val往右走
            if (curr->val > val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return ans;
    }
};