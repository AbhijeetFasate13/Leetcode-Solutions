class Solution {
    vector<string> ans;
    void pre() {
        for (int i = 1; i < 20; i++) {
            string inv = ans[i - 1];
            for (auto& i : inv) {
                if (i == '1')
                    i = '0';
                else
                    i = '1';
            }
            reverse(inv.begin(), inv.end());
            ans[i] = ans[i - 1] + '1' + inv;
        }
    }

public:
    Solution() {
        ans.resize(20);
        ans[0] = "0";
        pre();
    }
    char findKthBit(int n, int k) { return ans[n - 1][k - 1]; }
};