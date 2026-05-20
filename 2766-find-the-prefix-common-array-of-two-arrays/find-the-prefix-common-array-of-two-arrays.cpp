class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> ans;
        int n = A.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            ans.insert(A[i]);
            ans.insert(B[i]);
            res[i] = (2 * (i + 1)) - ans.size();
        }
        return res;
    }
};