class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;
        for (const auto& i : descriptions) {
            int parent = i[0], child = i[1], isLeft = i[2];
            if (!mp.count(child))
                mp[child] = new TreeNode(child);
            if (!mp.count(parent))
                mp[parent] = new TreeNode(parent);

            if (isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];

            children.insert(child);
        }

        for (const auto& [val, node] : mp) {
            if (!children.count(val))
                return node;
        }

        return nullptr;
    }
};