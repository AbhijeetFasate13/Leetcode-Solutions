class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> replacementParent, replacementChild;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (replacementParent.find(s[i]) == replacementParent.end() and
                replacementChild.find(t[i]) == replacementChild.end()) {
                replacementParent[s[i]] = t[i];
                replacementChild[t[i]] = s[i];
            } else {
                if (replacementParent[s[i]] != t[i] or
                    replacementChild[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};