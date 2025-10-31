class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n + 1; k++) {
                // xor(l,r) = prefix[l-1]^prefix[r]
                // here, prefix[i] represents xor of all numbers before i
                // so, if prefix[i]^prefix[j] == prefix[j]^prefix[k]
                // simplifying above equation we get...
                if (prefix[i] == prefix[k]) {
                    count += k - i - 1;
                }
            }
        }
        return count;
    }
};