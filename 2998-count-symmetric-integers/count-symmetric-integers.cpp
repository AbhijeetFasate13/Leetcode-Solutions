class Solution {
    int sum(const string s, const int& start, const int& end) {
        int halfSum = 0;
        for (int i = start; i < end; i++) {
            halfSum += (s[i] - '0');
        }
        return halfSum;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            string num = to_string(i);
            int len = (int)num.size();

            if (len & 1)
                continue;

            if (sum(num, 0, len / 2) == sum(num, len / 2, len)) {
                count++;
            }
        }
        return count;
    }
};