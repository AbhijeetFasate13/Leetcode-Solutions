class Solution {
    string generateKey(string s) {
        sort(s.begin(), s.end());
        return s;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (const auto& i : strs) {
            anagrams[generateKey(i)].push_back(i);
        }
        vector<vector<string>> solutionSet;
        for (const auto& i : anagrams) {
            solutionSet.push_back(i.second);
        }
        return solutionSet;
    }
};