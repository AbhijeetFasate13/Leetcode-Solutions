class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and st.top() <= nums[i]) {
                st.pop();
            }
            st.push(nums[i]);
        }
        vector<int> NGE(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and st.top() <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                NGE[i] = st.top();
            }
            st.push(nums[i]);
        }
        return NGE;
    }
};