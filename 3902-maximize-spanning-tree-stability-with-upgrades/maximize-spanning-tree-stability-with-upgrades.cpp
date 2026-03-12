class Solution {
    struct DSU {
        vector<int> p, r;
        DSU(int n) {
            p.resize(n);
            iota(p.begin(), p.end(), 0); // initialize parent to self
            r.resize(n, 0); // rank for union by rank
        }
        int find(int i) {
            if (p[i] == i) return i;
            return p[i] = find(p[i]); // path compression
        }
        bool unite(int i, int j) {
            int root_i = find(i), root_j = find(j);
            if (root_i != root_j) {
                if (r[root_i] < r[root_j]) p[root_i] = root_j;
                else if (r[root_i] > r[root_j]) p[root_j] = root_i;
                else { p[root_j] = root_i; r[root_i]++; }
                return true;
            }
            return false;
        }
    };

    bool check(int X, int n, const vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int comps = n;
        
        // First pass: form components using mandatory and 0-cost optional edges
        for (const auto& e : edges) {
            if (e[3] == 1) { // mandatory edge
                if (e[2] < X) return false; // mandatory edge breaks stability target
                if (dsu.unite(e[0], e[1])) comps--;
            } else if (e[2] >= X) { // optional edge requiring 0 upgrades
                if (dsu.unite(e[0], e[1])) comps--;
            }
        }
        
        // number of extra edges we need is exactly comps - 1
        if (comps - 1 > k) return false; // not enough upgrade budget
        
        // second pass: use 1-upgrade optional edges to connect remaining components
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < X && e[2] * 2 >= X) { // optional edge needing 1 upgrade
                if (dsu.unite(e[0], e[1])) comps--;
            }
        }
        
        return comps == 1; // true if all nodes are connected
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int min_mandatory = 200000;
        DSU dsu(n);
        int comps = n;
        
        // validation check for mandatory cycles and minimum mandatory strength
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (!dsu.unite(e[0], e[1])) return -1; // mandatory edges form a cycle
                comps--;
                min_mandatory = min(min_mandatory, e[2]);
            }
        }
        
        // validation check to see if the entire graph can even be connected
        for (const auto& e : edges) {
            if (e[3] == 0 && dsu.unite(e[0], e[1])) comps--;
        }
        
        if (comps > 1) return -1; // disconnected graph even with all edges
        
        // Binary search the max stability (minimum edge strength)
        int low = 1, high = min(200000, min_mandatory), ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, n, edges, k)) {
                ans = mid;
                low = mid + 1; // search for higher possible stability
            } else {
                high = mid - 1; // stability is too high to achieve
            }
        }
        
        return ans;
    }
};