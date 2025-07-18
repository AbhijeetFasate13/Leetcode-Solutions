class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        int m = s1.length(), n = s2.length();
        sort(s1.begin(), s1.end());
        for (int i = 0; i <= n - m; i++) {
            string temp = s2.substr(i, m);
            sort(begin(temp), end(temp));
            if (s1 == temp) {
                return true;
            }
        }
        return false;
    }
};