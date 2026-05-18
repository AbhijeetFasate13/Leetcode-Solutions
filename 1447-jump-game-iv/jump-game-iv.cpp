class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(0);
        vis[0] = 1;
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front();
                q.pop();
                if (i == n - 1)
                    return steps;
                vector<int> next = mp[arr[i]];
                next.push_back(i - 1);
                next.push_back(i + 1);

                for (int ni : next) {

                    if (ni >= 0 && ni < n && !vis[ni]) {
                        vis[ni] = 1;
                        q.push(ni);
                    }
                }
                mp[arr[i]].clear();
            }
            steps++;
        }
        return n-1;
    }
};