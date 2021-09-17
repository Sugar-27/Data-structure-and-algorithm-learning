// N叉树的层序遍历

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr)    return {};
        vector<vector<int>> ans;
        queue<pair<Node* , int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            Node* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (ans.size() <= depth)    ans.push_back({});
            ans[depth].push_back(node->val);
            for (Node* child : node->children) {
                q.push(make_pair(child, depth +　1));
            }
        }
        return ans;
    }
};