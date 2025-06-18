class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long int revX = 0;
        long long int temp = x;
        while (temp) {
            revX = revX * 10 + temp % 10;
            temp /= 10;
        }
        return revX == x;
    }
};