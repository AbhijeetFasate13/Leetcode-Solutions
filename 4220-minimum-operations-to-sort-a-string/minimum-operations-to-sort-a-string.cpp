
class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(s.begin(), s.end()))
            return 0;

        if (s.size() == 2)
            return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[s.size() - 1] == mx)
            return 1;

        int n = s.size();
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx)
                return 2;
        }

        return 3;
    }
};
