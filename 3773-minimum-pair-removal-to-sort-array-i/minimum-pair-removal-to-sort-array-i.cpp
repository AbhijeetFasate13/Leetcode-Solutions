class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        bool nonDec = true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                nonDec = false;
                break;
            }
        }
        if (nonDec) return 0;
        int minIdx = 0;
        int minSum = nums[0] + nums[1];
        for (int i = 1; i < n - 1; i++) {
            int s = nums[i] + nums[i + 1];
            if (s < minSum) {
                minSum = s;
                minIdx = i;
            }
        }

        vector<int> next;
        for (int i = 0; i < n; i++) {
            if (i == minIdx) {
                next.push_back(nums[i] + nums[i + 1]);
                i++;
            } else {
                next.push_back(nums[i]);
            }
        }

        return 1 + minimumPairRemoval(next);
    }
};
