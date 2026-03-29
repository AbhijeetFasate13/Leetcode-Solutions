class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int> freq(26);
        freq[s1[0] - 'a']++;
        freq[s1[2] - 'a']++;
        freq[s2[0] - 'a']--;
        freq[s2[2] - 'a']--;
        for (const int& i : freq)
            if (i != 0)
                return false;
        freq[s1[1] - 'a']++;
        freq[s1[3] - 'a']++;
        freq[s2[1] - 'a']--;
        freq[s2[3] - 'a']--;
        for (const int& i : freq)
            if (i != 0)
                return false;
        return true;
    }
};