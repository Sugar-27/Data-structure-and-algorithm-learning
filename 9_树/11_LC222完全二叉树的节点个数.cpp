// 看作普通的二叉树：
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            ++ans;
            if (node->left) q.push({node->left, depth + 1});
            if (node->right) q.push({node->right, depth + 1});
        }
        return ans;
    }
};

// 利用完全二叉树的特性
// 完全二叉树只有最后一行可能不是满的，如果是一颗满二叉树，则其节点个数为（2^树高 - 1）
// 对于不是一颗满二叉树，最后一行的节点也可以看作一个满二叉树，通过递归可以找到节点个数
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        int l_depth = 0, r_depth = 0;
        while (l) {
            l = l->left;
            ++l_depth;
        }
        while (r) {
            r = r->right;
            ++r_depth;
        }
        if (l_depth == r_depth) {
            return ((2 << l_depth) - 1);
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};