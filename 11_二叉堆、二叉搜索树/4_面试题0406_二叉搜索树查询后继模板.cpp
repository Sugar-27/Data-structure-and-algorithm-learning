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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return findSuccc(root, p->val);
    }

private:
    TreeNode* findSuccc(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* ans = nullptr;
        while (curr != nullptr) {
            if (curr->val > val) {
                if (ans == nullptr || ans->val > curr->val) { // case2：当后继存在于经过的点中
                    // 在所有大于val的点中找最小的
                    ans = curr;
                }
            }
            if (curr->val == val) {
                if (curr->right != nullptr) {
                    curr = curr->right;
                    while (curr->left != nullptr) {
                        curr = curr->left;
                    }
                    return curr;
                }
                break;
            }
            // 循环逻辑：当前值大于val往左走，小于val往右走
            if (curr->val > val)    curr = curr->left;
            else curr = curr->right;
        }
        return ans;
    }
};