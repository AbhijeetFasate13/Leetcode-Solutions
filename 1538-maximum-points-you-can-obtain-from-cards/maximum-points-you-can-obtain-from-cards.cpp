class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = (int)cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0) -
                  accumulate(cardPoints.begin(), cardPoints.begin() + n-k, 0);
        int maxSum = sum;
        int l = 0;
        cout<<sum<<endl;
        for (int r = n-k; r < n; r++) {
            sum -= cardPoints[r];
            sum += cardPoints[l++];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};