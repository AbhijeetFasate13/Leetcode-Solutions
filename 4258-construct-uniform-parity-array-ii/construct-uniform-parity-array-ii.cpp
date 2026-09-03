class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX, minEven = INT_MAX;
        for (const int& num : nums1) {
            if (num % 2 == 0)
                minEven = min(minEven, num);
            else
                minOdd = min(minOdd, num);
        }
        if (minOdd == INT_MAX or minEven == INT_MAX)
            return true;

        return minOdd < minEven;
    }
};