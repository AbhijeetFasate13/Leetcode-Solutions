class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        vector<int> freq(n, 0);
        int common = 0;
        for (int i = 0; i < n; i++) {

            freq[A[i]-1]++;
            if (freq[A[i]-1] == 2)
                common++;
            freq[B[i]-1]++;
            if (freq[B[i]-1] == 2)
                common++;
            ans[i] = common;
        }

        return ans;
    }
};