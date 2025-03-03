class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = (int)nums.size();
        int ptr = 0, equals = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[ptr++] = nums[i];
            } else if (nums[i] == pivot) {
                equals++;
            }
        }
        while (equals--) {
            ans[ptr++] = pivot;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) {
                ans[ptr++] = nums[i];
            }
        }
        return ans;
    }
};