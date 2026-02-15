class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        if (m < n) {
            swap(a, b);
            swap(m, n);
        }
        int carry = 0;
        int aPtr = m - 1, bPtr = n - 1;
        while (aPtr >= 0 and bPtr >= 0) {
            carry += a[aPtr] - '0';
            carry += b[bPtr] - '0';
            a[aPtr] = (carry % 2) + '0';
            carry = (carry > 1);
            aPtr--;
            bPtr--;
        }
        while (aPtr >= 0) {
            carry += a[aPtr] - '0';
            a[aPtr] = (carry % 2) + '0';
            carry = (carry > 1);
            aPtr--;
        }
        if (carry) {
            a = '1' + a;
        }
        return a;
    }
};