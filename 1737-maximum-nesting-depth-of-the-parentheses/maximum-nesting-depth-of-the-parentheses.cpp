class Solution {
public:
    int maxDepth(string s) {
        int counter = 0, maxm = 0;
        for (const char& c : s) {
            if (c == '(')
                counter++;
            else if (c == ')')
                counter--;
            maxm = max(maxm, counter);
        }
        return maxm;
    }
};