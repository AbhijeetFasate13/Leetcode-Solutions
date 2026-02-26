class Solution {
    vector<int> bfs(const int& id, const int& level,
                    const vector<vector<int>>& friends) {
        int n = friends.size();
        queue<int> q;
        vector<int> visited(n);
        q.push(id);
        visited[id] = true;
        int currLevel = 0;
        vector<int> kthLevelFriends;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front();
                q.pop();
                if (level == currLevel) {
                    kthLevelFriends.push_back(curr);
                }
                for (const int& nbr : friends[curr]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            currLevel++;
        }
        return kthLevelFriends;
    }
    unordered_map<string, int>
    getFrequencyMap(const vector<int>& kthLevelFriends,
                    const vector<vector<string>>& watchedVideos) {
        unordered_map<string, int> mp;
        for (const int& Friend : kthLevelFriends)
            for (const string& video : watchedVideos[Friend])
                mp[video]++;
        return mp;
    }

public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {
        unordered_map<string, int> mp =
            getFrequencyMap(bfs(id, level, friends), watchedVideos);

        vector<pair<int, string>> freqAndVideo;
        for (const auto& [video, freq] : mp) {
            freqAndVideo.push_back({freq, video});
        }
        sort(freqAndVideo.begin(), freqAndVideo.end());
        vector<string> ans;
        for (const auto& [_, video] : freqAndVideo) {
            ans.push_back(video);
        }
        return ans;
    }
};