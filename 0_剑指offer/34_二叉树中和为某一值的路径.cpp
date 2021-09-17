// dfs
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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        find(root, target);
        return ans;
    }

private:
    void find(TreeNode* root, int target) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        target -= root->val;
        if (!root->left && !root->right && target == 0) {
            ans.push_back(path);
        }
        find(root->left, target);
        find(root->right, target);
        path.pop_back();
    }
    vector<vector<int>> ans;
    vector<int> path;
};