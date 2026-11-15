class Solution {
    const int mod = 1e9 + 7;

public:
    int numOfSubarrays(vector<int>& arr) {
        int runningSum = 0;
        int evenSums = 1, oddSums = 0;
        int total = 0;
        for (const int& num : arr) {
            runningSum += num;
            if (runningSum & 1) {
                total += evenSums;
                oddSums++;
            } else {
                total += oddSums;
                evenSums++;
            }
            total %= mod;
        }
        return total;
    }
};