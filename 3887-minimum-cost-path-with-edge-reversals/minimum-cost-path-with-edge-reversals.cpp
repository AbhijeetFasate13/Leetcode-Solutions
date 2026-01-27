class Solution {
    const int INF = 1000000000;
    vector<vector<pair<int, int>>> adj;

    void dijkstra(int s, vector<int>& d) {
        int n = adj.size();
        d.assign(n, INF);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        d[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [dist, v] = pq.top();
            pq.pop();

            if (dist > d[v])
                continue;

            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    pq.push({d[to], to});
                }
            }
        }
    }

public:
    int minCost(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        for (const auto& v : edges) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], 2 * v[2]});
        }

        vector<int> d(n);
        dijkstra(0, d);

        return d[n - 1] == INF ? -1 : d[n - 1];
    }
};
