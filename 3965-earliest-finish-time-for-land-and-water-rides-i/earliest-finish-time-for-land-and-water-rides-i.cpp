class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int minTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Land first -> then water
                int timeA = landStartTime[i] + landDuration[i];
                if (timeA < waterStartTime[j]) {
                    timeA = waterStartTime[j];
                }
                timeA += waterDuration[j];

                // Water first -> then land
                int timeB = waterStartTime[j] + waterDuration[j];
                if (timeB < landStartTime[i]) {
                    timeB = landStartTime[i];
                }
                timeB += landDuration[i];

                minTime = min({minTime, timeA, timeB});
            }
        }

        return minTime;
    }
};
