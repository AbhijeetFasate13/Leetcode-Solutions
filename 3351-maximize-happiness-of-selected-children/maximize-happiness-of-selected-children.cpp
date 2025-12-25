class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq(happiness.begin(), happiness.end());
        int penalty = 0;
        long long happinessSum = 0;
        while (k--) {
            happinessSum += pq.top() - penalty;
            pq.pop();
            penalty++;
            if (pq.top() - penalty <= 0)
                break;
        }
        return happinessSum;
    }
};