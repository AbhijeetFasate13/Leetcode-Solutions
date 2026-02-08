class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        for (const auto& i : nums) {
            long long int curr = i;
            while (!st.empty() and st.top() == curr) {
                curr *= 2;
                st.pop();
            }
            st.push(curr);
        }
        int n = st.size();
        vector<long long> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};