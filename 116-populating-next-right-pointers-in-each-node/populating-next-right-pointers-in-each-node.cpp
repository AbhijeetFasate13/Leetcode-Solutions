/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root)
            q.push(root);
        int sz;
        while (!q.empty()) {
            sz = q.size();
            for (int i = 0; i < sz; i++) {
                Node* curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                if (i == sz - 1)
                    continue;
                if (!q.empty()) {
                    curr->next = q.front();
                }
            }
        }
        return root;
    }
};