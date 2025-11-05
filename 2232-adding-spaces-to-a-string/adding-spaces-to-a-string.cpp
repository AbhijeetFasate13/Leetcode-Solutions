class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string sWithSpaces;
        for (int i = 0; i < s.size(); i++) {
            if (binary_search(spaces.begin(), spaces.end(), i)) {
                sWithSpaces += " ";
            }
            sWithSpaces += s[i];
        }
        return sWithSpaces;
    }
};