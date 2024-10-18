class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        int n = (int)words.size();
        for (const auto& i : words) {
            mp[i]++;
        }
        vector<string> ans = words;
        sort(ans.begin(), ans.end(), [&](const string& a, const string& b) {
            return mp[a] == mp[b] ? a < b : mp[a] > mp[b];
        });

        for (int i = n - 1; i >= 0; i--) {
            if (mp.size() == k)
                break;
            mp.erase(ans[i]);
        }

        vector<string> finalq;
        for (const auto& i : ans) {
            if (mp.find(i) != mp.end()) {
                finalq.push_back(i);
                mp.erase(i);
            }
        }
        return finalq;
    }
};