class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int ptr1 = -1, ptr2 = -1, n = (int)nums.size();
        int mini = INT_MAX, minIdx = -1;
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) < mini) {
                ptr1 = -1, ptr2 = -1;
                mini = abs(nums[i]);
                minIdx = i;
                if (i < n - 1) {
                    ptr2 = i + 1;
                }
                if (i > 0) {
                    ptr1 = i - 1;
                }
                // break;
            }
        }
        ans.push_back(nums[minIdx] * nums[minIdx]);
        if (ptr1 == -1 or ptr2 == -1) {
            ans = nums;
            for (auto& i : ans) {
                i = i * i;
            }
            if (ptr2 == -1) {
                reverse(ans.begin(), ans.end());
            }
            return ans;
        } else if (ptr1 == -1 and ptr2 == -1) {
            return {nums[0] * nums[0]};
        }
        while (ptr1 >= 0 and ptr2 <= n - 1) {
            int a = nums[ptr1] * nums[ptr1], b = nums[ptr2] * nums[ptr2];
            if (a <= b) {
                ans.push_back(a);
                ptr1--;
            } else {
                ans.push_back(b);
                ptr2++;
            }
        }
        while (ptr1 >= 0) {
            int a = nums[ptr1] * nums[ptr1];
            ans.push_back(a);
            ptr1--;
        }
        while (ptr2 <= n - 1) {
            int b = nums[ptr2] * nums[ptr2];

            ans.push_back(b);
            ptr2++;
        }
        return ans;
    }
};