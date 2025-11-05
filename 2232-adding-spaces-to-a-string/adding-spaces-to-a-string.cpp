class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string sWithSpaces;
        int spacesArrItr = 0;
        for (int i = 0; i < s.size(); i++) {
            if (spacesArrItr < spaces.size() and i == spaces[spacesArrItr]) {
                sWithSpaces += " ";
                spacesArrItr++;
            }
            sWithSpaces += s[i];
        }
        return sWithSpaces;
    }
};