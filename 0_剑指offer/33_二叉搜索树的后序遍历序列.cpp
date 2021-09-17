// 递归分治，时间复杂度O(N^2)，空间复杂度O(N)

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return check(postorder, 0, postorder.size() - 1);
    }

private:
    bool check(vector<int>& postorder, int i, int j) {
        // 终止条件：当 i >= j，说明此子树节点数量小于等于1，无需判别正确性，因此直接返回true；
        if (i >= j) return true;
        int p = i;
        // 划分左子树
        while (postorder[p] < postorder[j]) p++;
        int m = p;
        // 划分右子树
        while (postorder[p] > postorder[j]) p++;
        // 所有子树都正确即可判定是一颗二叉搜索树
        return p == j && check(postorder, i, m - 1) && check(postorder, m, j - 1);
    }
};

// 单调栈辅助，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        // 初始值设为正无穷，可以理解为给定的树是正无穷的左子树
        int root = INT_MAX;
        for (int i = postorder.size() - 1; i >= 0; --i) {
            // 左子树所有的值都应该小于root，如果大于直接判错
            if (postorder[i] > root)    return false;
            // postorder[i] < stk.top()时更新root
            while (!stk.empty() && postorder[i] < stk.top()) {
                root = stk.top();
                stk.pop();
            }
            // 当前节点入栈
            stk.push(postorder[i]);
        }
        return true;
    }
private:
    stack<int> stk;
};