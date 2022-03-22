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
        if (root == nullptr)
            return;
        if (ans.size() == depth)
            ans.push_back({});
        ans[depth].push_back(root->val);
        print(root->left, depth + 1);
        print(root->right, depth + 1);
    }
    vector<vector<int>> ans;
};

// 双端队列解法，无需反转数组
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
        if (!root)
            return {};
        deque<TreeNode*> q;
        q.push_back(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            vector<int> temp;
            for (int i = q.size(); i > 0; --i) {
                temp.push_back(q.front()->val);
                if (q.front()->left)
                    q.push_back(q.front()->left);
                if (q.front()->right)
                    q.push_back(q.front()->right);
                q.pop_front();
            }
            ans.push_back(temp);
            if (q.empty())
                break;
            temp.clear();
            for (int i = q.size(); i > 0; --i) {
                temp.push_back(q.back()->val);
                if (q.back()->right)
                    q.push_front(q.back()->right);
                if (q.back()->left)
                    q.push_front(q.back()->left);
                q.pop_back();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};