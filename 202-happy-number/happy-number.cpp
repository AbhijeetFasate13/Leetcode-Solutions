class Solution {
    int calc(int n) {
        int sum = 0;
        while (n) {
            int rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        while (n % 10 == 0)
            n /= 10;
        int slow = n, fast = n;
        while (fast != 1) {
            slow = calc(slow);
            fast = calc(fast);
            fast = calc(fast);
            // cout << slow << " " << fast << endl;
            if (slow == fast) {
                return false;
            }
        }
        return true;
    }
};