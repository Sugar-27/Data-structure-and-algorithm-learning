// 检验一个二叉树是不是完全二叉树
// 一言以蔽之：对于一颗完全二叉树，层序遍历（BFS）的过程中遇到第一个空节点之后不应该再出现非空节点

// 写法一：按照顺序思路的写法
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool check = false;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t->left) {
                if (check) return false;
                q.push(t->left);
            }
            else check = true;
            if (t->right) {
                if (check) return false;
                q.push(t->right);
            }
            else check = true;
        }
        return true;
    }
};

// 写法二：简化思路写法，把空指针也放入到队列中
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool check = false;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            // 遇到第一个空节点之后不应该再出现非空节点
            if (t && check) return false;
            if (!t) {
                check = true;
                continue;
            }
            q.push(t->left);
            q.push(t->right);
        }
        return true;
    }
};