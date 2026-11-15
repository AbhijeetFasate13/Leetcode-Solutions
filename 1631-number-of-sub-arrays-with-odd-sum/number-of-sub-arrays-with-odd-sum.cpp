class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int runningSum = 0;
        int evenSums = 1, oddSums = 0;
        int total = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            runningSum += arr[i];
            if (runningSum & 1) {
                total = (total + evenSums) % mod;
                oddSums++;
            } else {
                total = (total + oddSums) % mod;
                evenSums++;
            }
        }
        return total;
    }
};