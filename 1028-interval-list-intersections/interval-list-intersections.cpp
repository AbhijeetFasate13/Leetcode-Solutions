class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f,
                                             vector<vector<int>>& s) {
        vector<vector<int>> ans;
        vector<int> temp(2);
        int ptr1 = 0, ptr2 = 0;
        int n = (int)f.size(), m = (int)s.size();
        while (ptr1 < n and ptr2 < m) {
            int a = f[ptr1][0], b = f[ptr1][1];
            int x = s[ptr2][0], y = s[ptr2][1];
            if (a <= x and b >= y) {
                ans.push_back({x, y});
                ptr2++;
            } else if (a <= x and x <= b) {
                ans.push_back({x, b});
                ptr1++;
            } else if (a >= x and b <= y) {
                ans.push_back({a, b});
                ptr1++;
            } else if (a >= x and a <= y) {
                ans.push_back({a, y});
                ptr2++;
            } else {
                // ans.push_back({a, b});
                // ans.push_back({x, y});
                b >= y ? ptr2++ : ptr1++;
            }
        }
        // while (ptr1 < n) {
        //     ans.push_back({f[ptr1][0], f[ptr1][1]});
        //     ptr1++;
        // }
        // while (ptr2 < m) {
        //     ans.push_back({s[ptr2][0], s[ptr2][1]});
        //     ptr2++;
        // }
        return ans;
    }
};