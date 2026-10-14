class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        while (sum) {
            if (sum >= 9) {
                ans.push_back('9');
                sum -= 9;
            } else {
                ans.push_back(sum + '0');
                sum = 0;
            }
        }
        if (ans.length() > num)
            return "";
        if (ans.length() == num and sum)
            return "";
        while (ans.length() < num)
            ans.push_back('0');
        return ans;
    }
};