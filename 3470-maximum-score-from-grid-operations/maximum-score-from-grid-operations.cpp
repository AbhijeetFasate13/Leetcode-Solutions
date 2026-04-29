class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int size = grid.size();
        if (size == 1)
            return 0;

        vector<long long> dpPrevClosed(size + 1, 0);
        vector<long long> dpPrevOpen(size + 1, 0);

        for (int col = 1; col < size; col++) {
            vector<long long> dpCurrClosed(size + 1, 0);
            vector<long long> dpCurrOpen(size + 1, 0);

            for (int splitRow = 0; splitRow <= size; splitRow++) {
                long long prevColumnSum = 0;
                long long currentColumnSum = 0;

                for (int r = 0; r < splitRow; r++)
                    currentColumnSum += grid[r][col];

                for (int nextRow = 0; nextRow <= size; nextRow++) {
                    if (nextRow > 0 && nextRow <= splitRow) {
                        currentColumnSum -= grid[nextRow - 1][col];
                    }
                    if (nextRow > splitRow) {
                        prevColumnSum += grid[nextRow - 1][col - 1];
                    }

                    dpCurrClosed[nextRow] =
                        max({dpCurrClosed[nextRow],
                             prevColumnSum + dpPrevClosed[splitRow],
                             dpPrevOpen[splitRow]});

                    dpCurrOpen[nextRow] =
                        max({dpCurrOpen[nextRow],
                             currentColumnSum + dpPrevOpen[splitRow],
                             currentColumnSum + prevColumnSum +
                                 dpPrevClosed[splitRow]});
                }
            }

            dpPrevClosed = dpCurrClosed;
            dpPrevOpen = dpCurrOpen;
        }

        return *max_element(dpPrevOpen.begin(), dpPrevOpen.end());
    }
};