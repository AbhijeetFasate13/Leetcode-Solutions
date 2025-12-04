class Solution {
public:
    int countCollisions(string directions) {
        char prev = directions[0];
        int cars = 0;
        int collisions = 0;
        for (int i = 1; i < directions.size(); i++) {
            char curr = directions[i];
            if (prev == curr) {
                cars += prev == 'R' ? 1 : prev == 'L' ? -1 : 0;
                continue;
            }
            bool RL = (prev == 'R' and curr == 'L');
            bool SL = (prev == 'S' and curr == 'L');
            bool RS = (prev == 'R' and curr == 'S');
            if (RL or SL or RS) {
                collisions += (RL ? 2 : 1) + cars;
                prev = 'S';
            } else {
                prev = curr;
            }
            cars = 0;
        }
        return collisions;
    }
};