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
        for (string s : seqBuild) {
            str.append(s + ",");
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s;
        for (char& ch : data) {
            if (ch == ',') {
                seqDeBuild.push_back(s);
                s.clear();
            } else {
                s.push_back(ch);
            }
        }
        curr = 0;
        return deBuild();
    }

private:
    void build(TreeNode* root) {
        if (root == nullptr) {
            seqBuild.push_back("null");
            return;
        }
        seqBuild.push_back(to_string(root->val));
        build(root->left);
        build(root->right);
    }

    TreeNode* deBuild() {
        if (seqDeBuild[curr] == "null") {
            ++curr;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(seqDeBuild[curr]));
        curr++;
        root->left = deBuild();
        root->right = deBuild();
        return root;
    }

    vector<string> seqBuild;
    vector<string> seqDeBuild;
    string str;
    int curr;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));