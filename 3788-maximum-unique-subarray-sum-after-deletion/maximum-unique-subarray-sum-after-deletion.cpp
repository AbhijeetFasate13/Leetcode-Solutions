class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (const int& i : nums) {
            mp[i]++;
        }
        int sum = 0;
        for (const auto& [a, b] : mp) {
            if (a > 0)
                sum += a;
        }
        return sum == 0 ? *max_element(begin(nums), end(nums)) : sum;
    }
};