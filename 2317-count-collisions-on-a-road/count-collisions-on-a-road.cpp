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
            if (prev == 'R' and curr == 'L') {
                collisions += 2 + cars;
                cars = 0;
                prev = 'S';
            } else if (prev == 'S' and curr == 'L') {
                collisions += 1 + cars;
                cars = 0;
                prev = 'S';
            } else if (prev == 'R' and curr == 'S') {
                collisions += 1 + cars;
                cars = 0;
                prev = 'S';
            } else {
                prev = curr;
                cars = 0;
            }
        }
        return collisions;
    }
};