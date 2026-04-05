class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0, horizontal = 0;
        for (const char& c : moves) {
            if (c == 'U')
                vertical++;
            else if (c == 'D')
                vertical--;
            else if (c == 'R')
                horizontal++;
            else
                horizontal--;
        }
        return vertical == 0 and horizontal == 0;
    }
};