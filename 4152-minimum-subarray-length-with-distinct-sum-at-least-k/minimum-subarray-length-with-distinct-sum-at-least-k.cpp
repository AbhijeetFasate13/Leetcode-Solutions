class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0;
        int distinctSum = 0, minLength = INT_MAX;
        for (int r = 0; r < nums.size(); r++) {
            if (freq.find(nums[r]) == freq.end()) {
                distinctSum += nums[r];
            }
            freq[nums[r]]++;
            while (distinctSum >= k) {
                minLength = min(minLength, r - l + 1);
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    distinctSum -= nums[l];
                    freq.erase(nums[l]);
                }
                l++;
            }
        }
        return minLength==INT_MAX?-1:minLength;
    }
};