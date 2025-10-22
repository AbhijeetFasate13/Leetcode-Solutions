class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string zigZag;
        int modder = 2 * numRows - 2;
        vector<string> rows(numRows);
        int row;
        for (int i = 0; i < s.size(); i++) {
            row = i % modder;
            if (row >= numRows)
                row = modder - row;
            rows[row].push_back(s[i]);
        }
        for (int i = 0; i < numRows; i++) {
            zigZag += rows[i];
        }
        return zigZag;
    }
};