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
class Solution {
   public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return nullptr;

        // 创建新节点，新节点的值取决于root1和root2的值，如果为nullptr则认为值为0（因为一定会有一个有值）
        TreeNode* root = new TreeNode(0);
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