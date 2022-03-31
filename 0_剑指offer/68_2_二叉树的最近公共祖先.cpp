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
        findFather(root);
        redNodes.insert(root->val);
        while (p != root) {
            redNodes.insert(p->val);
            p = father[p->val];
        }
        while (redNodes.find(q->val) == redNodes.end()) q = father[q->val];
        return q;
    }

private:
    void findFather(TreeNode* root) {
        if (root == nullptr)    return;
        if (root->left != nullptr) {
            father[root->left->val] = root;
            findFather(root->left);
        }
        if (root->right != nullptr) {
            father[root->right->val] = root;
            findFather(root->right);
        }
    }

    unordered_map<int, TreeNode*> father;
    set<int> redNodes;
};

// 超高效率递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == root || q == root) {
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
    
        return l == nullptr ? r : (r == nullptr ? l : root);
    }
};

// 逻辑更清晰的版本
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 先把两边都有的情况判出去
        if (left && right) return root;
        // 再考虑在一边的情况
        return left ? left : right;
    }
};