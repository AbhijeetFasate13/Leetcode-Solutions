class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1Idx;
        int m = nums1.size();
        for (int i = 0; i < m; i++) {
            nums1Idx[nums1[i]] = i;
        }
        vector<int> NGE(m, -1);
        stack<int> st;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and st.top() <= nums2[i]) {
                st.pop();
            }
            if (nums1Idx.find(nums2[i]) != nums1Idx.end() and !st.empty()) {
                NGE[nums1Idx[nums2[i]]] = st.top();
            }
            st.push(nums2[i]);
        }
        return NGE;
    }
};