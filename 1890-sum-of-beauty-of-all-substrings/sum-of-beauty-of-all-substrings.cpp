class Solution {
    int calcBeauty(vector<int>& charFreq) {
        int maxi = -1, mini = INT_MAX;
        for (const auto& i : charFreq) {
            if (i > 0) {
                maxi = max(maxi, i);
                mini = min(mini, i);
            }
        }
        return maxi - mini;
    }
    int beautyForWindowSize(int windowSize, string s) {
        int n = s.size();
        vector<int> charFreq(26);
        for (int i = 0; i < windowSize; i++) {
            charFreq[s[i] - 'a']++;
        }
        int beauty = calcBeauty(charFreq);
        for (int i = windowSize; i < n; i++) {
            charFreq[s[i] - 'a']++;
            charFreq[s[i - windowSize] - 'a']--;
            beauty += calcBeauty(charFreq);
        }
        return beauty;
    }

public:
    int beautySum(string s) {
        int sumOfBeauty = 0;
        for (int len = 3; len <= s.size(); len++) {
            sumOfBeauty += beautyForWindowSize(len, s);
        }
        return sumOfBeauty;
    }
};