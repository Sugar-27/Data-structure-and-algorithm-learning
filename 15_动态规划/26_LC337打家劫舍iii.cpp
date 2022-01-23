// 树形dp，将dp融合到dfs的遍历二叉树中
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
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;

        dp[root] = {0, root->val};
        if (root->left) {
            dp[root][0] += rob(root->left);
            dp[root][1] += dp[root->left][0];
        }
        if (root->right) {
            dp[root][0] += rob(root->right);
            dp[root][1] += dp[root->right][0];
        }
        return max(dp[root][0], dp[root][1]);
    }

   private:
    unordered_map<TreeNode*, vector<int>> dp;
};