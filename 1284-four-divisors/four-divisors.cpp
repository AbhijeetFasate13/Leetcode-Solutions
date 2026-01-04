class Solution {
public:
    int sumOfDivisorsOfNum(int n) {
        int sum = 0;
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                count++;
                if (n / i != i) {
                    sum += n / i;
                    count++;
                }
                if (count > 4)
                    return 0;
            }
        }
        return count == 4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (const int& i : nums) {
            ans += sumOfDivisorsOfNum(i);
        }
        return ans;
    }
};