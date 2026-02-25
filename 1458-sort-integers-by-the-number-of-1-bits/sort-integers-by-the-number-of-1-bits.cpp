class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), [](const int& a, const int& b) {
            int aBits = __builtin_popcount(a);
            int bBits = __builtin_popcount(b);
            return aBits != bBits ? aBits < bBits : a < b;
        });
        return arr;
    }
};