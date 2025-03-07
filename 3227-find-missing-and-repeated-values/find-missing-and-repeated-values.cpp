class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<int> flat(n * n);
        int ptr = 0;
        int sum = 0;
        for (const auto& i : grid) {
            for (const auto& j : i) {
                flat[ptr++] = j;
                sum += j;
            }
        }
        ptr = 0;
        int flag;
        vector<int> ans(2);
        while (ptr != n * n) {
            if (flat[ptr] == ptr + 1)
                continue;
            flag = 0;
            while (flat[ptr] != ptr + 1) {
                if (flat[ptr] == flat[flat[ptr] - 1]) {
                    ans[0] = flat[ptr];
                    flag = 1;
                    break;
                }
                swap(flat[ptr], flat[flat[ptr] - 1]);
            }
            if (flag)
                break;
            ptr++;
        }
        ans[1] = ((n * n) * ((n * n) + 1)) / 2 - sum + ans[0];

        return ans;
    }
};