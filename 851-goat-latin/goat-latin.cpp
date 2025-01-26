class Solution {
    bool isVowel(char c) {
        if (c >= 'A' and c <= 'Z') {
            c -= 'A';
            c += 'a';
        }
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < 5; i++) {
            if (c == vowels[i])
                return true;
        }
        return false;
    }

public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        int n = (int)words.size();
        for (int i = 0; i < n; i++) {
            if (!isVowel(words[i][0])) {
                words[i] = words[i].substr(1) + words[i][0];
            }
            words[i] += "ma";
            for (int j = 0; j < i + 1; j++) {
                words[i].push_back('a');
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            ans += words[i];
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};