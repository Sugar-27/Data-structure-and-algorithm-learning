// 从前序与中序遍历构建二叉树

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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    // 通过preorder[l1~r1]，inorder[l2~r2]复原
    TreeNode* build(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        if (l1 > r1) {
            return nullptr;
        }
        // 通过找到根在中序（inorder）里面的位置，确定左右子树大小
        TreeNode* root = new TreeNode(preorder[l1]);
        int mid = l2;
        while (inorder[mid] != root->val) ++mid;
        int leftSize = mid - l2;
        // [3,9,20,15,7]
        // [9,3,15,20,7]
        // int rightSize = r2 - mid;
        // 递归复原
        root->left = build(preorder, l1 + 1, l1 + leftSize, inorder, l2, mid - 1);
        root->right = build(preorder, l1 + leftSize + 1, r1, inorder, mid + 1, r2);
        return root;
    }
};

/*
    // [3 | 9 | 20,15,7] 告诉我们root=3，不知道左右子树的大小
    // [9 | 3 | 15,20,7] 告诉我们左子树1个点，右子树3个点
        l2  mid       r2

      [3]
    /    \
  [9]   [20,15,7]
  [9]   [15,20,7]
*/