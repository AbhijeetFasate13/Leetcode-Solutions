class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            swap(a, b);
        }
        int sum = 0, carry = 0;
        string addition;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < b.size(); i++) {
            int x = a[i] - '0', y = b[i] - '0';
            sum = carry ^ x ^ y;
            carry = ((carry + x + y) > 1);
            addition.push_back(sum + '0');
        }
        for (int i = b.size(); i < a.size(); i++) {
            int x = a[i] - '0';
            sum = carry ^ x;
            carry = (carry + x) > 1;
            addition.push_back(sum + '0');
        }
        if (carry) {
            addition.push_back('1');
        }
        reverse(addition.begin(), addition.end());
        return addition;
    }
};