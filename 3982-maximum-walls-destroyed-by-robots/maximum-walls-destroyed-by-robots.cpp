class Solution {
public:
    struct Robot {
        int position;
        int distance;
    };

    static const int INF = INT_MAX;
    static const int negInf = INT_MIN;

    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        vector<Robot> robotRecords(n);

        for (int i = 0; i < n; i++) {
            robotRecords[i] = {robots[i], distance[i]};
        }

        sort(robotRecords.begin(), robotRecords.end(),
             [](const Robot& a, const Robot& b) {
                 return a.position < b.position;
             });

        sort(walls.begin(), walls.end());

        return solve(robotRecords, walls);
    }

private:
    int solve(vector<Robot>& robots, vector<int>& walls) {
        int n = robots.size();

        vector<int> leftWall = prepareLeftWall(robots, walls);
        vector<int> rightWall = prepareRightWall(robots, walls);
        vector<int> common = prepareCommon(robots, walls);

        vector<int> dpLeft(n), dpRight(n);

        dpLeft[0] = leftWall[0];
        dpRight[0] = rightWall[0];

        for (int i = 1; i < n; i++) {
            dpLeft[i] =
                leftWall[i] + max(dpLeft[i - 1], dpRight[i - 1] - common[i]);
            dpRight[i] = rightWall[i] + max(dpLeft[i - 1], dpRight[i - 1]);
        }

        return max(dpLeft[n - 1], dpRight[n - 1]);
    }

    vector<int> prepareLeftWall(vector<Robot>& robots, vector<int>& walls) {
        int n = robots.size();
        int m = walls.size();

        vector<int> leftWall(n);
        int left = 0, right = -1;

        for (int i = 0; i < n; i++) {
            int prevPos = (i == 0 ? negInf : robots[i - 1].position);
            int shootStart =
                max(prevPos + 1, robots[i].position - robots[i].distance);
            int shootEnd = robots[i].position;

            while (right + 1 < m && walls[right + 1] <= shootEnd)
                right++;
            while (left < m && walls[left] < shootStart)
                left++;

            if (left <= right)
                leftWall[i] = right - left + 1;
        }

        return leftWall;
    }

    vector<int> prepareRightWall(vector<Robot>& robots, vector<int>& walls) {
        int n = robots.size();
        int m = walls.size();

        vector<int> rightWall(n);
        int left = 0, right = -1;

        for (int i = 0; i < n; i++) {
            int nextPos = (i == n - 1 ? INF : robots[i + 1].position);
            int shootStart = robots[i].position;
            int shootEnd =
                min(nextPos - 1, robots[i].position + robots[i].distance);

            while (right + 1 < m && walls[right + 1] <= shootEnd)
                right++;
            while (left < m && walls[left] < shootStart)
                left++;

            if (left <= right)
                rightWall[i] = right - left + 1;
        }

        return rightWall;
    }

    vector<int> prepareCommon(vector<Robot>& robots, vector<int>& walls) {
        int n = robots.size();
        int m = walls.size();

        vector<int> common(n);
        int left = 0, right = -1;

        for (int i = 1; i < n; i++) {
            int shootStart = max(robots[i - 1].position + 1,
                                 robots[i].position - robots[i].distance);
            int shootEnd = min(robots[i].position - 1,
                               robots[i - 1].position + robots[i - 1].distance);

            if (shootStart > shootEnd)
                continue;

            while (right + 1 < m && walls[right + 1] <= shootEnd)
                right++;
            while (left < m && walls[left] < shootStart)
                left++;

            if (left <= right)
                common[i] = right - left + 1;
        }

        return common;
    }
};