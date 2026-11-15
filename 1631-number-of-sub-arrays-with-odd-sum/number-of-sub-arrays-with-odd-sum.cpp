class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = arr[i] + prefix[i - 1];
        }

        int evenSums = 1, oddSums = 0;
        int total = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            if (prefix[i] & 1) {
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