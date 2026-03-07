class Solution {
    int calcSecondBest(const unordered_map<int, int>& mp, const int& banned) {
        int ansEl, maxFreq = 0;
        for (const auto& [el, freq] : mp) {
            if (freq > maxFreq and el != banned) {
                maxFreq = freq;
                ansEl = el;
            }
        }
        return maxFreq;
    }

public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> odd, even;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i & 1)
                odd[nums[i]]++;
            else
                even[nums[i]]++;
        }
        int evenMaxFreq = 0, evenEl, oddMaxFreq = 0, oddEl;
        for (const auto& [el, freq] : even) {
            if (freq > evenMaxFreq) {
                evenMaxFreq = freq;
                evenEl = el;
            }
        }
        for (const auto& [el, freq] : odd) {
            if (freq > oddMaxFreq) {
                oddMaxFreq = freq;
                oddEl = el;
            }
        }
        if (evenEl != oddEl) {
            return n - evenMaxFreq - oddMaxFreq;
        } else {
            return min(n - evenMaxFreq - calcSecondBest(odd, oddEl),
                       n - oddMaxFreq - calcSecondBest(even, evenEl));
        }
    }
};