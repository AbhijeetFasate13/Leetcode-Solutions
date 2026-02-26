class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int moves = 0, carry = 0;
        for (int i = n - 1; i > 0; i--) {
            if (s[i] == '1') {
                for (int j = i; j > 0; j--) {
                    if (j == 1 and s[j] == '1') {
                        moves++;
                    }
                    if (s[j] == '1') {
                        s[j] = '0';
                    } else {
                        s[j] = '1';
                        break;
                    }
                }
                i++;
                moves++;
            } else {
                moves++;
            }
        }
        return moves;
    }
};