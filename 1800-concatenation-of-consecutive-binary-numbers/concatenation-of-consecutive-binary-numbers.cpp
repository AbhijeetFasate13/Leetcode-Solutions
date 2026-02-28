class Solution {
public:
    int concatenatedBinary(int n) {
        const long long MOD = 1e9 + 7;
        int ans = 0, temp;
        stack<int> st;
        for (int i = 1; i <= n; i++) {
            temp = i;
            while (temp) {
                st.push(temp & 1);
                temp >>= 1;
            }
            while (!st.empty()) {
                ans *= 2;
                ans %= MOD;
                ans += st.top();
                ans %= MOD;
                st.pop();
            }
        }
        return ans;
    }
};