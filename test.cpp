#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* build_tree(vector<int>& tree) {
    int n = tree.size();
    vector<TreeNode*> build(tree.size(), nullptr);
    for (int i = 0; i < n; ++i) {
        if (tree[i] == -1) continue;
        TreeNode* node = new TreeNode(tree[i]);
        build[i] = node;
    }
    TreeNode* root = build[0];
    for (int i = 0; i * 2 + 2 < n; ++i) {
        if (!build[i]) continue;
        build[i]->left = build[i * 2 + 1];
        build[i]->right = build[i * 2 + 2];
    }
    return root;
}

void dfs(TreeNode* root) {
    if (!root) {
        cout << "NULL" << endl;
        return;
    }
    cout << root->val << " ";
    dfs(root->left);
    dfs(root->right);
}

void print(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* tmp = q.front();
            q.pop();
            if (!tmp) cout << "NULL" << " ";
            else cout << tmp->val << " ";
            if (tmp) {
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        cout << endl;
    }
}

int main() {
    vector<int> vec = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* root = build_tree(vec);
    print(root);
    return 0;
}