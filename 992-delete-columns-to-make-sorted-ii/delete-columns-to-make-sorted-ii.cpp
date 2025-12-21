class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int deletions = 0;
        vector<bool> isAlreadySorted(n);
        for (int col = 0; col < strs[0].size(); col++) {
            bool isDeleted = false;
            for (int row = 0; row < n - 1; row++) {
                if (!isAlreadySorted[row] and
                    strs[row][col] > strs[row + 1][col]) {
                    deletions++;
                    isDeleted = true;
                    break;
                }
            }
            if (isDeleted)
                continue;
            for (int row = 0; row < n - 1; row++) {
                isAlreadySorted[row] = isAlreadySorted[row] |
                                       (strs[row][col] < strs[row + 1][col]);
            }
        }
        return deletions;
    }
};