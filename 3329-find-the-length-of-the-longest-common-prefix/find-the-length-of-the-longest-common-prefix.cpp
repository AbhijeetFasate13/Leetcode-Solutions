class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for (int x : arr1) {
            while (x > 0) {
                st.insert(x);
                x /= 10;
            }
        }

        int ans = 0;
        for (int x : arr2) {
            int y = x;
            while (y > 0) {
                if (st.count(y)) {
                    ans = max(ans, (int)to_string(y).size());
                    break;
                }
                y /= 10;
            }
        }

        return ans;
    }
};

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();