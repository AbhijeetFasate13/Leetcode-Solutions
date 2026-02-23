class Solution {
    bool isPalindrome(const string& word) {
        int start = 0, end = word.length() - 1;
        while (start < end) {
            if (word[start++] != word[end--])
                return false;
        }
        return true;
    }
    void backtrack(string s, int start, vector<string>& curr,
                   vector<vector<string>>& ans) {
        if (start == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int end = start; end < s.length(); end++) {
            string newWord = s.substr(start, end - start + 1);
            if (isPalindrome(newWord)) {
                curr.push_back(newWord);
                backtrack(s, end + 1, curr, ans);
                curr.pop_back();
            }
        }
        return;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(s, 0, curr, ans);
        return ans;
    }
};