// 二叉树的最近公共祖先
// 优化方法，简单递归
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (right == nullptr)
            return left;
        if (left == nullptr)
            return right;
        return root;
    }
};

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        calcFather(root);
        // p往上走到根，标红色
        redNodes.insert(root->val);
        while (p->val != root->val) {
            redNodes.insert(p->val);
            p = father[p->val];
        }
        // q往上走到第一个碰到红点时
        while (redNodes.find(q->val) == redNodes.end()) {
            q = father[q->val];
        }
        return q;
    }

   private:
    // 深度优先遍历求father
    void calcFather(TreeNode* root) {
        if (root == nullptr)
            return;
        if (root->left != nullptr) {
            father[root->left->val] = root;
            calcFather(root->left);
        }
        if (root->right != nullptr) {
            father[root->right->val] = root;
            calcFather(root->right);
        }
    }

    unordered_map<int, TreeNode*> father;
    set<int> redNodes;
};