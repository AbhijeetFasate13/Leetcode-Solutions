class Solution {
    int calcWaviness(int x) {
        if (x / 100 == 0)
            return 0;
        int next = x % 10, curr, prev;
        x /= 10;
        int count = 0;
        while (x) {
            curr = x % 10;
            x /= 10;
            if (!x)
                break;
            prev = x % 10;
            if ((prev < curr && curr > next) || (prev > curr && curr < next)) {
                count++;
            }
            next = curr;
        }
        return count;
    }

public:
    int totalWaviness(int num1, int num2) {
        int sum = 0;
        for (int i = num1; i <= num2; i++) {
            sum += calcWaviness(i);
        }
        return sum;
    }
};