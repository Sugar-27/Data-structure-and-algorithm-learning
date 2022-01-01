/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
/*
二叉搜索树删除节点的模版题，遍历树，找节点
删除思路：
    遍历的root的值大于要删的节点值key：要删的节点值在root的左子树中，因此对当前左子树进行删除key的操作，删除完key的左子树成为新的左子树
    遍历的root的值小于要删的节点值key：要删的节点值在root的右子树中，因此对当前右子树进行删除key的操作，删除完key的右子树成为新的右子树
    遍历的root的值等于要删的节点值key：找到了要删的节点，接下来考虑如何删除它。删除一个节点并保持二叉树不变，已知其实就是找到比删除的节点值小或者大一个节点来代替它，这样子替换不会影响到其他节点，因此接下来的问题就变成了找到要替换的节点然后把值赋给要删除的节点，然后删除要替换的节点就可以了。找到要替换的节点很简单，这里以后继为例后继者，因为节点值已经存在，因此找它的后继只需要找到它的右子树然后一路向左遍历即可。

具体细节看代码～
*/
class Solution {
   public:
    // 在以root为根的子树中删除key，返回新的根
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key) {
            if (root->left == nullptr)
                return root->right;  // 没有左子树，让right代替root的位置
            if (root->right == nullptr)
                return root->left;  // 没有右子树，让left代替root的位置
            TreeNode* next = root->right;
            while (next->left != nullptr)
                next = next->left;  // 找后继：右子树一路向左
            root->right = deleteNode(root->right, next->val);
            root->val = next->val;
        }
        // key在树的右子树里面
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        // key在树的左子树里面
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        return root;
    }
};