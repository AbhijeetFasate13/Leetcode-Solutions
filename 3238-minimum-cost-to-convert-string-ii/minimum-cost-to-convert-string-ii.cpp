class Solution {
    unordered_map<string, long long int> strToId;
    unordered_set<long long int> lens;
    const long long int INF = 1e15;

    vector<vector<long long int>> adj;
    vector<long long> dp;
    string source, target;

    void mapToIds(const vector<string>& v) {
        for (const string& s : v) {
            if (!strToId.count(s)) {
                strToId[s] = strToId.size();
                lens.insert(s.size());
            }
        }
    }

    void floydWarshall(long long int n) {
        for (long long int k = 0; k < n; k++) {
            for (long long int i = 0; i < n; i++) {
                if (adj[i][k] >= INF)
                    continue;
                for (long long int j = 0; j < n; j++) {
                    if (adj[k][j] < INF) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
    }

    long long rec(long long int idx) {
        if (idx == source.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        long long ans = INF;

        // Case 1: characters already match
        if (source[idx] == target[idx]) {
            ans = rec(idx + 1);
        }

        // Case 2: try only valid substring lengths
        for (long long int len : lens) {
            if (idx + len > source.size())
                continue;

            string s1 = source.substr(idx, len);
            string s2 = target.substr(idx, len);

            if (strToId.count(s1) && strToId.count(s2)) {
                long long int u = strToId[s1];
                long long int v = strToId[s2];
                if (adj[u][v] < INF) {
                    ans = min(ans, adj[u][v] + rec(idx + len));
                }
            }
        }

        return dp[idx] = ans;
    }

public:
    long long minimumCost(string src, string tgt, vector<string>& original,
                          vector<string>& changed, vector<int>& cost) {
        source = src;
        target = tgt;

        mapToIds(original);
        mapToIds(changed);

        int n = strToId.size();
        adj.assign(n, vector<long long int>(n, INF));
        for (int i = 0; i < n; i++)
            adj[i][i] = 0;

        for (int i = 0; i < cost.size(); i++) {
            long long int u = strToId[original[i]];
            long long int v = strToId[changed[i]];
            adj[u][v] = min(adj[u][v], cost[i] * 1ll);
        }

        floydWarshall(n);

        dp.assign(source.size(), -1);
        long long res = rec(0);

        return res >= INF ? -1 : res;
    }
};
