class Solution {
    int longestBalancedWithOneChar(const string& s) {
        int currLen = 1, maxLen = 1;
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1])
                currLen++;
            else {
                maxLen = max(maxLen, currLen);
                currLen = 1;
            }
        }
        return max(maxLen, currLen);
    }

    int longestBalancedWithTwoChars(const string& s, const char& first,
                                    const char& second) {
        unordered_map<int, int> mp;
        int n = s.size();
        int firstChar = 0, secondChar = 0;
        int ans = 0;
        mp[0] = -1;
        int currDiff;
        for (int i = 0; i < n; i++) {
            if (s[i] == first) {
                firstChar++;
                secondChar--;
            } else if (s[i] == second) {
                secondChar++;
                firstChar--;
            } else {
                mp.clear();
                mp[0] = i;
                firstChar = secondChar = 0;
                continue;
            }
            currDiff = secondChar - firstChar;
            if (mp.find(currDiff) != mp.end())
                ans = max(ans, i - mp[currDiff]);
            else
                mp[currDiff] = i;
        }
        return ans;
    }

    int longestBalancedWithThreeChars(const string& s) {
        map<pair<int, int>, int> mp;
        int n = s.size();
        int a = 0, b = 0, c = 0;
        int ans = 0;
        mp[{0, 0}] = -1;
        pair<int, int> curr;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                a++;
            else if (s[i] == 'b')
                b++;
            else
                c++;
            curr = {b - a, c - a};
            if (mp.find(curr) != mp.end())
                ans = max(ans, i - mp[curr]);
            else
                mp[curr] = i;
        }
        return ans;
    }

public:
    int longestBalanced(string s) {
        return max({longestBalancedWithOneChar(s),
                    longestBalancedWithTwoChars(s, 'a', 'b'),
                    longestBalancedWithTwoChars(s, 'b', 'c'),
                    longestBalancedWithTwoChars(s, 'a', 'c'),
                    longestBalancedWithThreeChars(s)});
    }
};