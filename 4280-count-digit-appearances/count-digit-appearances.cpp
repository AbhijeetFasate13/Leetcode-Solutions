class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        string num;
        int count = 0;
        for (int i = 0; i < n; i++) {
            while (nums[i]) {
                if ((nums[i] % 10) == digit)
                    count++;
                nums[i] /= 10;
            }
        }
        return count;
    }
};