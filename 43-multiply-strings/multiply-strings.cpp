class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string result(n + m, '0');
        for (int i = n - 1; i >= 0; i--) {
            int carry = 0;
            int a = num1[i] - '0';  
            for (int j = m - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                int product = (result[i + j + 1] - '0') + (a * b) + carry;
                result[i + j + 1] = (product % 10) + '0';
                carry = product / 10;
            }       
            result[i] = carry + '0';
        }
        // Remove leading '0's
        int i = 0;
        while (i < n + m - 1 && result[i] == '0') {
            i++;
        }
        return result.substr(i);
    }
};
