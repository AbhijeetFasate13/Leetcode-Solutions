class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0, r = n - 1;
        while (l < n and directions[l] == 'L')
            l++;
        while (r >= 0 and directions[r] == 'R')
            r--;
        int collisions = 0;
        if (l <= r)
            for (int i = l; i <= r; i++) {
                if (directions[i] != 'S')
                    collisions++;
            }
        return collisions;
    }
};