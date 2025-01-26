class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (auto& i : paragraph) {
            if (i >= 'a' and i <= 'z')
                continue;
            if (i >= 'A' and i <= 'Z') {
                i -= 'A';
                i += 'a';
            } else {
                i = ' ';
            }
        }
        cout << paragraph << endl;
        map<string, int> freq;
        stringstream ss(paragraph);
        string word;
        int maxi = 1;
        while (ss >> word) {
            if (find(banned.begin(), banned.end(), word) == banned.end()) {
                freq[word]++;
                maxi = max(maxi, freq[word]);
            }
        }
        for (const auto& i : freq) {
            if (i.second == maxi) {
                word = i.first;
                break;
            }
        }
        return word;
    }
};