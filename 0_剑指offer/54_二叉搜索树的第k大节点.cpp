// 二叉搜索树的性质：中序遍历序列为递增序列
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 正常根左右进行中序遍历，遍历结束找倒数第k个值
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        find(root);
        return sorts[sorts.size() - k];
    }
private:
    void find(TreeNode* root) {
        if (root == nullptr)    return;
        find(root->left);
        sorts.push_back(root->val);
        find(root->right);
    }
    vector<int> sorts;
};

// 优化，对中序进行反向遍历，即右根左，遍历到第k个结束
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        find(root);
        return sorts[k - 1];
    }
private:
    void find(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        find(root->right);
        sorts.push_back(root->val);
        k--;
        if (k == 0) return;
        find(root->left);
    }
    int k;
    vector<int> sorts;
};

// 再优化，因为只返回一个int值，因此只用一个int维护结果即可
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        find(root);
        return res;
    }
private:
    void find(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        find(root->right);
        if (--k == 0) {
            res = root->val;
            return;
        }
        find(root->left);
    }
    int k;
    int res;
};