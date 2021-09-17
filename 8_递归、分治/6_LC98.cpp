// 递归验证二叉搜索树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    /*
    节点的左子树只包含小于当前节点的数 => 左子树的最大节点比根小
    节点的右子树只包含大于当前节点的数 => 右子树的最小节点比根大
    所有左子树和右子树自身必须也是二叉搜索树。
    */
public:
    bool isValidBST(TreeNode* root) {
        return check(root)->isValid;
    }

private:
    struct Info {
        bool isValid;
        long long minVal;
        long long maxVal;
    };

    Info* check(TreeNode* root) {
        if (root == nullptr) {
            Info* temp = new Info();
            temp->isValid = true;
            temp->maxVal = INT_MIN - 1ll;
            temp->minVal = INT_MAX + 1ll;
            return temp;
        }
        Info* left = check(root->left);
        Info* right = check(root->right);
        Info* result = new Info();
        result->isValid = left->isValid && right->isValid && left->maxVal < root->val && right->minVal > root->val;
        result->minVal = min(min(left->minVal, right->minVal),(long long)root->val);
        result->maxVal = max(max(left->maxVal, right->maxVal), (long long)root->val);
        return result;
    }
};