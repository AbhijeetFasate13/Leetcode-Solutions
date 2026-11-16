class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        if (n <= k)
            return s;

        int sum = 0;
        string newStr;
        for (int i = 0; i < n; i += k) {
            sum = 0;
            for (int j = i; j < min(i + k, n); j++) {
                sum += (s[j] - '0');
            }
            newStr += to_string(sum);
        }
        return digitSum(newStr, k);
    }
};