class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits;
        stack<int> st;
        for (int i : nums) {
            while (i) {
                st.push(i % 10);
                i /= 10;
            }
            while (!st.empty()) {
                digits.push_back(st.top());
                st.pop();
            }
        }
        return digits;
    }
};