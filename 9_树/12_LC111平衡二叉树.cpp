class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
private:
    int check(TreeNode* root) {
        if (!root) return 0;
        int left_height = check(root->left);
        if (left_height == -1) return -1;
        int right_height = check(root->right);
        if (right_height == -1) return -1;
        return abs(left_height - right_height) <= 1 ? max(left_height, right_height) + 1 : -1;
    }
};