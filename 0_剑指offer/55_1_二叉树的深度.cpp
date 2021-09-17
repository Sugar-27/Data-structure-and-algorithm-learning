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
    int maxDepth(TreeNode* root) {
        depth = 0;
        exDepth(root, 1);
        return depth;
    }
private:
    void exDepth(TreeNode* root, int index) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            depth = max(depth, index);
            return;
        }
        exDepth(root->right, index + 1);
        exDepth(root->left, index + 1);
    }
    int depth;
};