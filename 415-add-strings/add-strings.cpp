class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        int carry = 0;
        
        if (n < m) {
            swap(num1, num2);
            swap(n, m);
        }
        
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--, j--) {
            int a = num1[i] - '0';
            int b = (j >= 0) ? (num2[j] - '0') : 0;
            int sum = a + b + carry;
            num1[i] = '0' + sum % 10;
            carry = sum / 10;
        }
        
        if (carry) {
            return '1' + num1;
        }
        
        return num1;
    }
};
