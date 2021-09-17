// 解题关键：二叉搜索树的中序遍历是递增序列
// 先用dfs进行中序遍历，遍历的过程中对每一次递归的根节点进行操作，使得双向链表是有序递增的
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)    return nullptr;
        dfs(root);
        pre->right = head;
        head->left = pre;
        return head;
    }
private:
    Node* pre;
    Node* head;
    void dfs(Node* root) {
        if (root == nullptr)    return;
        dfs(root->left);
        if (pre != nullptr) pre->right = root;
        else head = root;
        root->left = pre;
        pre = root;
        dfs(root->right);
    }
};