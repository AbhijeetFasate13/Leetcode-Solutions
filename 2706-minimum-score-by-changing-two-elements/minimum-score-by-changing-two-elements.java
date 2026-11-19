class Solution {
    public int minimizeSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int minGap = Integer.MAX_VALUE;
        int a = nums[0], b = nums[1];
        for (int i = 1; i < n; i++) {
            if (minGap > nums[i] - nums[i - 1]) {
                minGap = nums[i] - nums[i - 1];
                a = i - 1;
                b = i;
            }
        }

        int ans = Math.min(nums[n - 1] - nums[2], nums[n - 3] - nums[0]);

        nums[0] = nums[a];
        nums[n - 1] = nums[b];
        Arrays.sort(nums);

        return Math.min(ans, nums[n - 1] - nums[0]);
    }
}