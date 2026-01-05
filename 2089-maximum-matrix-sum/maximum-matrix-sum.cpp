class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg = 0, min = INT_MAX, absNum;
        long long sum = 0;
        for (const auto& row : matrix) {
            for (const auto& num : row) {
                if (num < 0)
                    neg++;
                absNum = abs(num);
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