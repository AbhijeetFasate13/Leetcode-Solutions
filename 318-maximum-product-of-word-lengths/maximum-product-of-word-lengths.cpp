class Solution {
    map<string, vector<int>> mp;
    void mapStringToCharFreq(const vector<string>& words) {
        for (const string& word : words) {
            vector<int> freq(26);
            for (const char& c : word) {
                freq[c - 'a']++;
            }
            mp[word] = freq;
            freq.clear();
        }
    }
    bool checkIfShareCommonLetters(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != 0 and b[i] != 0) {
                return false;
            }
        }
        return true;
    }

public:
    int maxProduct(vector<string>& words) {
        mapStringToCharFreq(words);

        int n = words.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (checkIfShareCommonLetters(mp[words[i]], mp[words[j]])) {
                    maxi = max(maxi, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return maxi;
    }
};