class Solution {
    string processed(vector<string>& words, int width, bool lastSentence) {
        int n = words.size();
        int len = 0;
        for (auto& w : words)
            len += w.size();

        if (n == 1) {
            return words[0] + string(width - len, ' ');
        }

        int spaces = width - len;
        int gaps = n - 1;
        int spaceEach = lastSentence ? 1 : spaces / gaps;
        int extra = lastSentence ? 0 : spaces % gaps;

        string sentence = words[0];
        for (int i = 1; i < n; i++) {
            int currSpaces = spaceEach + (extra > 0 ? 1 : 0);
            sentence += string(currSpaces, ' ') + words[i];
            if (extra > 0)
                extra--;
        }
        while (width - sentence.size() > 0) {
            sentence.push_back(' ');
        }
        return sentence;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justifiedText;
        int n = words.size();
        int temp = maxWidth;
        vector<string> curr;
        for (int i = 0; i < n; i++) {
            if (temp - (int)words[i].size() - (!curr.empty()) >= 0) {
                if (!curr.empty()) {
                    temp -= 1;
                }
                curr.push_back(words[i]);
                temp -= words[i].size();
            } else {
                justifiedText.push_back(processed(curr, maxWidth, false));
                curr.clear();
                temp = maxWidth;
                i--;
            }
        }
        justifiedText.push_back(processed(curr, maxWidth, true));
        return justifiedText;
    }
};