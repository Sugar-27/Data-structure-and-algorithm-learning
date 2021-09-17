// dfs+数组初始化+奇数行数组reverse
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        print(root, 0);
        for (int i = 0; i < ans.size(); ++i) {
            if (i % 2 == 1) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
private:
    void print(TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (ans.size() == depth)    ans.push_back({});
        ans[depth].push_back(root->val);
        print(root->left, depth + 1);
        print(root->right, depth + 1);
    }
    vector<vector<int>> ans;
};