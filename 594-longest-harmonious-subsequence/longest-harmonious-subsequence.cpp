class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> freq;
        for (const auto& i : nums) {
            freq[i]++;
        }

        int maxi =
            0; // Not 1 — because if no such pair exists, we should return 0

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            auto next_it =
                freq.find(it->first + 1); // Look for consecutive number
            if (next_it != freq.end()) {
                maxi = max(maxi, it->second + next_it->second);
            }
        }

        return maxi;
    }
};