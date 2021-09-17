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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A != nullptr && B != nullptr) && (check(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

private:
    bool check(TreeNode* A, TreeNode* B) {
        if (B == nullptr)   return true;
        if (A == nullptr || A->val != B->val)   return false;
        return check(A->left, B->left) && check(A->right, B->right);
    }
};