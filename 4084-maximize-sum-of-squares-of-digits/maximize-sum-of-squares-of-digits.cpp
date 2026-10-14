class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 1 or sum > 9 * num)
            return "";
        string ans(sum / 9, '9');
        if (sum % 9)
            ans.push_back((sum % 9) + '0');
        while (ans.length() < num)
            ans.push_back('0');
        return ans;
    }
};