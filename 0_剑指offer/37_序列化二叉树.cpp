// 利用中序遍历进行构建与复原
// 使用vector<string> 作为存储与复原的容器
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        build(root);
        string res;
        for (string s : buildSeq) {
            res.append(s + ",");
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s;
        for (char ch : data) {
            if (ch == ',') {
                reBuildSeq.push_back(s);
                s.clear();
            } else {
                s.push_back(ch);
            }
        }
        curr = 0;
        TreeNode* res = deBuild();
        return res;
    }

private:
    TreeNode* deBuild() {
        if (reBuildSeq[curr] == "null") {
            curr++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(reBuildSeq[curr]));
        curr++;
        root->left = deBuild();
        root->right = deBuild();
        return root;
    }
    void build(TreeNode* root) {
        if (root == nullptr) {
            buildSeq.push_back("null");
            return;
        }
        buildSeq.push_back(to_string(root->val));
        build(root->left);
        build(root->right);
    }
    vector<string> buildSeq;
    vector<string> reBuildSeq;
    int curr;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));