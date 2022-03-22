// 构建新树
class Solution {
   public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode* ans = new TreeNode(root->val);
        ans->left = mirrorTree(root->right);
        ans->right = mirrorTree(root->left);
        return ans;
    }
};

// 递归镜像
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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* temp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(temp);
        return root;
    }
};