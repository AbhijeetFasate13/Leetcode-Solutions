class Solution {
    unordered_map<string, int> mp;
public:
    Solution() {
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;
    }

    int romanToInt(string s) {
        int num = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i != n - 1) {
                string curr = s.substr(i, 2);
                if (mp.find(curr) != mp.end()) {
                    num += mp[curr];
                    i++;
                    continue;
                }
            }
            string single(1, s[i]);
            num += mp[single];
        }
        return num;
    }
};
