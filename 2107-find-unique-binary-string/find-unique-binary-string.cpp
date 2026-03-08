class Solution {
    string decToBinary(long long int num, const int& size) {
        string ans;
        while (num) {
            ans = (char)((num & 1) + '0') + ans;
            num >>= 1;
        }
        while (ans.size() < size) {
            ans = '0' + ans;
        }
        return ans;
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        if (nums.empty())
            return "";
        sort(begin(nums), end(nums));
        int n = nums[0].size();
        int limit = 1ll << (n - 1);
        for (long long int i = 0; i < n; i++) {
            if (stoi(nums[i], nullptr, 2) != i) {
                return decToBinary(i, n);
            }
        }
        return decToBinary(limit, n);
    }
};