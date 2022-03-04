// 递归找出二叉树的最大深度

// 记录局部变量depth，最容易理解的做法
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

   private:
    void dfs(TreeNode* root, int depth) {
        if (!root) {
            ans = max(ans, depth);
            return;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    int ans = 0;
};

// 极简解法
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//第二种递归方式，记录全局变量depth

class Solution {
   public:
    int maxDepth(TreeNode* root) {
        depth = 1;
        ans = 0;
        calc(root);
        return ans;
    }

   private:
    void calc(TreeNode* root) {
        if (root == nullptr)
            return;
        ans = max(ans, depth);
        depth++;
        calc(root->left);
        //还原现场
        // depth--;
        // depth++;
        calc(root->right);
        depth--;
    }

    int depth;
    int ans;
};