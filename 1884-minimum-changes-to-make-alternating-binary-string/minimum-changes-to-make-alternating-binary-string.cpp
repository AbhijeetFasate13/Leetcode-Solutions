class Solution {
public:
    int minOperations(string s) {
        int moves1 = 0, moves2 = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 and s[i] != '1')
                moves1++;
            else if (i & 1 and s[i] != '0')
                moves1++;
            if (i % 2 == 1 and s[i] != '1')
                moves2++;
            else if (i % 2 == 0 and s[i] != '0')
                moves2++;
        }
        return min(moves1, moves2);
    }
};