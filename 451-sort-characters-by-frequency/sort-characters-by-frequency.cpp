class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (const auto& i : s) {
            mp[i]++;
        }
        sort(s.begin(), s.end(), [&](const char& a, const char& b) {
            return mp[a] == mp[b] ? a < b : mp[a] > mp[b];
        });
        return s;
    }
};