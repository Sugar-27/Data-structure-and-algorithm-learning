// 验证一棵树是二叉搜索树，也就是验证其中序遍历是有序的
// 中序遍历的过程中使用pre记录上一个节点的值，刚开始的时候将其设置为一个最小的量用于第一个值进行比较
// 因为有序，所以只需要考虑这次的比上次大就可以了
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (root->val <= pre) return false;
        pre = root->val;
        if (!isValidBST(root->right)) return false;
        return true;
    }
private:
    long long pre = -(1ll << 33);
};