// 最优解，自底向上
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }

private:
    int check(TreeNode* root) {
        // 当越过叶子节点时，返回高度0
        if (root == nullptr)    return 0;
        int left = check(root->left);
        // 剪枝操作：当左（右）子树高度left == -1时，代表此子树的左（右）子树不是平衡树，因此直接返回-1
        if (left == -1) return -1;
        int right = check(root->right);
        if (right == -1)    return -1;
        // 当节点root左/右子树的高度差小于2，则返回以节点root为根节点的子树的最大高度，即节点root的左右子树中最大高度加1
        // 当节点root左/右子树的高度差大于1，则返回 -1，代表此子树不是平衡树
        return abs(right - left) < 2 ? max(right, left) + 1 : -1;
    }
};