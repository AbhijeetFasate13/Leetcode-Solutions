class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int deletions = 0;
        for (int i = 0; i < m; i++) {
            bool isColSorted = true;
            for (int j = 0; j < n - 1; j++) {
                if (strs[j][i] > strs[j + 1][i]) {
                    isColSorted = false;
                    break;
                }
            }
            if (!isColSorted) {
                deletions++;
            }
        }
        return deletions;
    }
};