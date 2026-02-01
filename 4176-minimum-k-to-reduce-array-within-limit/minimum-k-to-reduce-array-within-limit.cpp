class Solution {
    bool check(int k, vector<int>& nums) {
        long long moves = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            moves += (nums[i] + k - 1) / k;
        }

        return moves <= 1LL * k * k;
    }

public:
    int minimumK(vector<int>& nums) {
        int l = 1;
        int r = 1e9;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid, nums))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
