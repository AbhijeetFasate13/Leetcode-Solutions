class Solution {
    const int mod = 1e9 + 7;
    int calculateTriplets(const vector<int>& tripletIAndK,
                          const vector<int>& tripletJ) {
        int n = tripletIAndK.size(), m = tripletJ.size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            int val = tripletJ[i];
            long long int possibleIs =
                upper_bound(begin(tripletIAndK), end(tripletIAndK), val - 1) -
                tripletIAndK.begin();
            long long int possibleKs =
                tripletIAndK.end() -
                lower_bound(begin(tripletIAndK), end(tripletIAndK), val + 1);
            count = ((possibleIs * possibleKs) % mod + count) % mod;
        }
        return count % mod;
    }

public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int n = nums.size();
        int maxi = -1, mini = 1e5 + 5;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        int countTriplets = 0;
        for (int i = maxi; i >= min(maxi, 2 * mini); i--) {
            if (i & 1)
                continue;
            if (pos.find(i) != pos.end() and pos[i].size() > 1 and
                pos.find(i / 2) != pos.end()) {
                countTriplets =
                    (countTriplets + calculateTriplets(pos[i], pos[i / 2])) %
                    mod;
            }
        }
        return countTriplets;
    }
};