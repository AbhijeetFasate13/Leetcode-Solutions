class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (const auto& i : arr) {
            freq[i]++;
        }
        int max = -1;
        for (const auto& i : arr) {
            if (i == freq[i] and max < i) {
                max = i;
            }
        }
        return max;
    }
};