//递归找到二叉树的最小深度，需要注意题意，最小深度是叶子节点到根节点的最小深度

// 解法一：好理解
class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root, 0);
        return ans;
    }

   private:
    void dfs(TreeNode* root, int depth) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            ans = min(ans, depth + 1);
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    int ans = INT_MAX;
};

// 解法二：标准解法
class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        // 1.到达子节点，左右子树为空
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        // 2.未到达子节点，一边子树为空，需要继续递归
        else if (root->left == nullptr)
            return minDepth(root->right) + 1;
        else if (root->right == nullptr)
            return minDepth(root->left) + 1;
        // 3.未到达子节点，两边都不为空，找到左右子树的最小深度
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};