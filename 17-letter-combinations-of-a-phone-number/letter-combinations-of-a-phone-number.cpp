class Solution {
    unordered_map<char, string> digitsToLetters;

public:
    Solution() {
        digitsToLetters['2'] = "abc";
        digitsToLetters['3'] = "def";
        digitsToLetters['4'] = "ghi";
        digitsToLetters['5'] = "jkl";
        digitsToLetters['6'] = "mno";
        digitsToLetters['7'] = "pqrs";
        digitsToLetters['8'] = "tuv";
        digitsToLetters['9'] = "wxyz";
    }
    void backtrack(const string& digits, int idx, string& curr,
                   vector<string>& ans) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }
        for (const char& c : digitsToLetters[digits[idx]]) {
            curr.push_back(c);
            backtrack(digits, idx + 1, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        string curr;
        vector<string> ans;
        backtrack(digits, 0, curr, ans);
        return ans;
    }
};