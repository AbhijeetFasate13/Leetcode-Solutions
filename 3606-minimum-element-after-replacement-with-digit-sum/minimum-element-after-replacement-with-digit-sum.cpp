class Solution {
    int sumOfDigits(int a) {
        int sum = 0;
        while (a) {
            sum += a % 10;
            a /= 10;
        }
        return sum;
    }

public:
    int minElement(vector<int>& nums) {
        int minm = sumOfDigits(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            minm = min(minm, sumOfDigits(nums[i]));
        }
        return minm;
    }
};