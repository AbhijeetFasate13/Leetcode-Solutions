class Solution {
    static constexpr int INF = 1e9;
    vector<vector<int>> adj;

    void bfs(int s, vector<int>& d) {
        int n = adj.size();
        d.assign(n, INF);

        queue<int> q;
        d[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : adj[v]) {
                if (d[to] == INF) {
                    d[to] = d[v] + 1;
                    q.push(to);
                }
            }
        }
    }

    bool isPythagoreanTriplet(long long a, long long b, long long c) {
        vector<long long> t = {a, b, c};
        sort(t.begin(), t.end());
        return t[0] * t[0] + t[1] * t[1] == t[2] * t[2];
    }

public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        adj.assign(n, {});
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> xD, yD, zD;
        bfs(x, xD);
        bfs(y, yD);
        bfs(z, zD);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (xD[i] == INF || yD[i] == INF || zD[i] == INF)
                continue;

            if (isPythagoreanTriplet(xD[i], yD[i], zD[i]))
                count++;
        }

        return count;
    }
};
