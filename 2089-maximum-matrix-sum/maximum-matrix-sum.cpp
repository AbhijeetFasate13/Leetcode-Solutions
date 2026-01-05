class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long neg = 0, min = INT_MAX, sum = 0;
        for (const auto& row : matrix) {
            for (const auto& num : row) {
                if (num < 0)
                    neg++;
                int absNum = abs(num);
                if (min > absNum)
                    min = absNum;
                sum += absNum;
            }
        }
        if (neg & 1) {
            sum -= 2 * min;
        }
        return sum;
    }
};