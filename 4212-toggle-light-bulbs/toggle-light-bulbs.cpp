class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> bulbStatus(101);
        for (const int& i : bulbs) {
            bulbStatus[i] = 1 - bulbStatus[i];
        }
        vector<int> ans;
        for (int i = 1; i < 101; i++) {
            if (bulbStatus[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};