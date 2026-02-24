class Solution {
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        int n = s.length();
        unordered_map<char, char> mp;
        unordered_set<char> st;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            char d = t[i];
            if (!mp.count(c)) {
                if (st.count(d))
                    return false;
                mp[c] = d;
                st.insert(d);
            } else if (mp[c] != d)
                return false;
        }
        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        vector<string> ans;
        for (const string& s : words) {
            if (isIsomorphic(s, pattern)) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};