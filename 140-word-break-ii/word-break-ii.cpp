class Solution {
    void backtrack(string& s, const vector<int>& lengths,
                   const vector<string>& wordDict, int start,
                   vector<string>& curr, set<vector<string>>& ans) {

        if (start == s.length()) {
            ans.insert(curr);
            return;
        }
        for (const int& length : lengths) {
            if (start + length > s.length())
                continue;
            string newWord = s.substr(start, length);
            if (binary_search(wordDict.begin(), wordDict.end(), newWord)) {
                curr.push_back(newWord);
                backtrack(s, lengths, wordDict, start + length, curr, ans);
                curr.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        vector<int> lengths;
        for (const string& word : wordDict) {
            if (lengths.empty() || lengths.back() != word.length()) {
                lengths.push_back(word.length());
            }
        }
        vector<string> curr;
        set<vector<string>> ans;
        backtrack(s, lengths, wordDict, 0, curr, ans);
        vector<string> results;
        for (const auto& it : ans) {
            string result;
            for (const string& word : it) {
                result += word + " ";
            }
            result.pop_back();
            results.push_back(result);
        }
        return results;
    }
};