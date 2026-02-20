/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* ans;
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ans = root;
        return "";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { return ans; }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));