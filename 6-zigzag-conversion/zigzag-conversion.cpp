class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string zigZag;
        vector<int> isTraversed(s.size());
        int modder = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.size(); j++) {
                if (isTraversed[j])
                    continue;
                if (j % modder == i or j % modder == modder - i) {
                    zigZag.push_back(s[j]);
                    isTraversed[j] = 1;
                }
            }
        }
        return zigZag;
    }
};