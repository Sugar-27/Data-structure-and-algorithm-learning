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
    vector<int> levelOrder(TreeNode* root) {
        bfs(root);
        return ans;
    }
private:
    void bfs(TreeNode* root) {
        if (root == nullptr)    return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            if (q.front()->left != nullptr) q.push(q.front()->left);
            if (q.front()->right != nullptr)    q.push(q.front()->right);
            q.pop();
        }
    }
    vector<int> ans;
};