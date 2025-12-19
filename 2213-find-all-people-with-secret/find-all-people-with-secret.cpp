class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& i : meetings) {
            int p1 = i[0], p2 = i[1], time = i[2];
            adj[p1].push_back({p2, time});
            adj[p2].push_back({p1, time});
        }
        vector<int> known(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        vector<int> list;
        while (!pq.empty()) {
            const auto [timeAtWhichSecretKnown, personWhoKnows] = pq.top();
            pq.pop();
            if (known[personWhoKnows] != INT_MAX)
                continue;
            known[personWhoKnows] = timeAtWhichSecretKnown;
            list.push_back(personWhoKnows);
            for (const auto& [nextPerson, meetingTime] : adj[personWhoKnows]) {
                if (known[nextPerson] != INT_MAX or
                    meetingTime < timeAtWhichSecretKnown)
                    continue;
                pq.push({meetingTime, nextPerson});
            }
        }
        return list;
    }
};