class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (const int& i : nums)
            freq[i]++;
        unordered_map<int, int> freqOfFreq;
        for (const auto& i : freq) {
            freqOfFreq[i.second]++;
        }
        int ans = -1;
        for (const int& i : nums) {
            if (freqOfFreq[freq[i]] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};