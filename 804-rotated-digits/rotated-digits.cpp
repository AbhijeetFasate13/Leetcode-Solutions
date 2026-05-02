class Solution {
    bool check(int a) {
        return a == 0 or a == 1 or a == 8 or a == 2 or a == 5 or a == 6 or
               a == 9;
    }
    bool check1(int a) { return a == 2 or a == 5 or a == 6 or a == 9; }

public:
    int rotatedDigits(int n) {
        int count = 0, temp;
        bool flag, isGood;
        for (int i = 1; i <= n; i++) {
            temp = i;
            flag = true;
            isGood = false;
            while (temp) {
                if (check(temp % 10)) {
                    if (check1(temp % 10))
                        isGood = true;
                    temp /= 10;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag and isGood)
                count++;
        }
        return count;
    }
};