class Solution {
public:
    int countMonobit(int n) {
        if (n == 0)
            return 1;
        int pow = log(n) / log(2);
        if (((n + 1) & n) == 0)
            pow++;
        return 1 + pow;
    }
};