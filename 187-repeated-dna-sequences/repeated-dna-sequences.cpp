class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n < 10)
            return {};
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i++) {
            freq[s.substr(i, 10)]++;
        }
        vector<string> ans;
        for (const auto& i : freq) {
            if (i.second > 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};