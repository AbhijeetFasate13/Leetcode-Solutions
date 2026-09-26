class Solution {
    unordered_map<string, string> mp;
    void fillMap(vector<vector<string>>& knowledge) {
        for (const auto& i : knowledge) {
            mp[i[0]] = i[1];
        }
    }

    void fillPlaceHolders(string& s) {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; i++) {
            if (i != n - 1 and s[i] == '(') {
                string curr;
                int j;
                for (j = i + 1; j < n; j++) {
                    if (s[j] == ')')
                        break;
                    curr.push_back(s[j]);
                }
                if (!mp.count(curr))
                    curr = "?";
                else
                    curr = mp[curr];
                for (const char& c : curr) {
                    ans.push_back(c);
                }
                i = j;
            } else {
                ans.push_back(s[i]);
            }
        }
        s = ans;
    }

public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        fillMap(knowledge);
        fillPlaceHolders(s);
        return s;
    }
};