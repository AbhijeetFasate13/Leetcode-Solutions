class Solution {
    vector<string> possibilities;
    vector<string> DigitToAlpha = {"",    "",    "abc",  "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void rec(const int& level, string currExplore, const string& digits) {
        if (level == digits.size()) {
            if (currExplore != "")
                possibilities.push_back(currExplore);
            return;
        }
        for (const auto c : DigitToAlpha[digits[level] - '0']) {
            currExplore += c;
            rec(level + 1, currExplore, digits);
            currExplore.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        rec(0, "", digits);
        return possibilities;
    }
};