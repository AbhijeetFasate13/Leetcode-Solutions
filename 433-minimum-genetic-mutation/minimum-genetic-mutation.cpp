class Solution {
    int canDrawEdge(const string& a, const string& b) {
        int mismatches = 0;
        for (int i = 0; i < 8; i++) {
            if (a[i] != b[i])
                mismatches++;
        }
        return mismatches;
    }

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene)
            return 0;
        unordered_map<string, vector<string>> adj;
        bank.push_back(startGene);
        int n = bank.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (canDrawEdge(bank[i], bank[j]) == 1) {
                    adj[bank[i]].push_back(bank[j]);
                    adj[bank[j]].push_back(bank[i]);
                }
            }
        }

        queue<string> q;
        q.push(startGene);
        set<string> visited;
        visited.insert(startGene);
        int mutations = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string currGene = q.front();
                q.pop();
                if (currGene == endGene)
                    return mutations;
                for (string& neighbour : adj[currGene]) {
                    if (!visited.count(neighbour)) {
                        visited.insert(neighbour);
                        q.push(neighbour);
                    }
                }
            }
            mutations++;
        }
        return -1;
    }
};