class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                st.insert(grid[r][c]);
                for (int k = 1; r + 2 * k < m && c - k >= 0 && c + k < n; k++) {
                    int sum = 0;
                    int x = r, y = c;
                    for (int i = 0; i < k; i++)
                        sum += grid[x + i][y - i];
                    for (int i = 0; i < k; i++)
                        sum += grid[x + k + i][y - k + i];
                    for (int i = 0; i < k; i++)
                        sum += grid[x + 2 * k - i][y + i];
                    for (int i = 0; i < k; i++)
                        sum += grid[x + k - i][y + k - i];
                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (auto it = st.rbegin(); it != st.rend() && ans.size() < 3; ++it)
            ans.push_back(*it);

        return ans;
    }
};