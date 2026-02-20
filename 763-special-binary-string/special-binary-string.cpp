class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials;
        int start = 0;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += s[i] == '1' ? 1 : -1;
            if (!sum) {
                specials.push_back(
                    "1" +
                    makeLargestSpecial(s.substr(1 + start, i - start - 1)) +
                    "0");
                start = i + 1;
            }
        }
        sort(begin(specials), end(specials), greater<string>());
        string ans;
        for (const string& str : specials) {
            ans += str;
        }
        return ans;
    }
};