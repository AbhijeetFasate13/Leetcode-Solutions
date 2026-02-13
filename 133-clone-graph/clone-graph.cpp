class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;
        q.push(node);
        oldToNew[node] = new Node(node->val);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (auto neighbor : curr->neighbors) {
                if (!oldToNew.count(neighbor)) {
                    oldToNew[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[neighbor]);
            }
        }

        return oldToNew[node];
    }
};
