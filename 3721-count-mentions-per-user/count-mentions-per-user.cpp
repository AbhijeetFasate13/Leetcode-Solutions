class Solution {
    vector<int> parseIds(const string& s, vector<int>& status,
                         const int& numberOfUsers, const int& timestamp) {
        vector<int> ids;
        if (s == "HERE" or s == "ALL") {
            for (int i = 0; i < numberOfUsers; i++) {
                if (s == "HERE" and status[i] <= timestamp) {
                    status[i] = 0;
                    ids.push_back(i);
                } else if (s == "ALL") {
                    ids.push_back(i);
                }
            }
            return ids;
        }
        string curr;
        for (const char& c : s) {
            if (c >= '0' and c <= '9') {
                curr.push_back(c);
            } else if (!curr.empty()) {
                ids.push_back(stoi(curr));
                curr = "";
            }
        }
        if (!curr.empty())
            ids.push_back(stoi(curr));
        return ids;
    }
    void updateStatus(const int& timestamp, const int& userId,
                      vector<int>& status) {
        status[userId] = timestamp + 60;
    }
    void updateMentions(vector<int>& currMentionedIds,
                        vector<int>& mentionsPerUser) {
        for (const int& id : currMentionedIds) {
            mentionsPerUser[id]++;
        }
    }

public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        vector<int> mentionsPerUser(numberOfUsers);
        // 0 denotes online
        vector<int> status(numberOfUsers);
        vector<int> currMentionedIds;
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);
            if (t1 != t2)
                return t1 < t2;

            return a[0] == "OFFLINE" && b[0] == "MESSAGE";
        });

        for (const auto& event : events) {
            if (event[0] == "OFFLINE") {
                updateStatus(stoi(event[1]), stoi(event[2]), status);
            } else {
                currMentionedIds =
                    parseIds(event[2], status, numberOfUsers, stoi(event[1]));
                // for (const auto& i : currMentionedIds) {
                //     cout << i << " ";
                // }
                // cout << endl;
                updateMentions(currMentionedIds, mentionsPerUser);
            }
        }
        return mentionsPerUser;
    }
};